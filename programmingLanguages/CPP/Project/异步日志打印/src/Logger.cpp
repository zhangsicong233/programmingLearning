/**
 * @file LoggerNew.cpp
 * @brief 异步日志器类实现文件
 *
 * 实现Logger_new.h中声明的非模板成员函数，包括工厂方法、构造函数、析构函数和写日志方法。
 */

#include "AsyncLogger/Logger.h"

/**
 * @brief 创建Logger实例的工厂方法
 * @param filename 日志文件路径
 * @return std::shared_ptr<Logger> 指向新Logger实例的shared_ptr
 * @throw std::runtime_error 如果无法打开日志文件
 *
 * 由于Logger构造函数是私有的，无法直接使用make_shared，因此使用new构造并通过shared_ptr管理。
 * 调用者应使用此方法获取Logger实例，而不是直接构造。
 */
std::shared_ptr<Logger> Logger::create(const std::string& filename) {
  return std::shared_ptr<Logger>(new Logger(filename));
}

/**
 * @brief 构造函数，打开日志文件并初始化资源
 * @param filename 日志文件路径
 * @throw std::runtime_error 如果无法打开日志文件
 *
 * 以追加模式打开指定的日志文件，如果打开失败则抛出异常。
 * 使用std::make_shared创建文件流和互斥体的共享指针，确保资源能被正确共享和释放。
 */
Logger::Logger(const std::string& filename) {
  _log_file =
      std::make_shared<std::ofstream>(filename, std::ios::out | std::ios::app);
  if (!_log_file->is_open()) {
    throw std::runtime_error("无法打开日志文件");
  }
  _file_mutex = std::make_shared<std::mutex>();
}

/**
 * @brief 析构函数
 *
 * 如果文件流仍处于打开状态，则关闭文件。由于使用了shared_ptr，文件流会在所有引用释放后自动关闭，
 * 此处显式关闭是为了确保日志在程序退出前被刷新。
 */
Logger::~Logger() {
  if (_log_file && _log_file->is_open()) {
    _log_file->close();
  }
}

/**
 * @brief 将格式化后的消息写入文件
 * @param msg 待写入的日志消息
 *
 * 此方法由线程池调用，每次写入受互斥锁保护，确保多线程环境下日志写入的线程安全。
 * 每条消息单独一行，并自动刷新（使用std::endl）。
 */
void Logger::writeLog(const std::string& msg) {
  std::lock_guard<std::mutex> lock(*_file_mutex);
  (*_log_file) << msg << std::endl;
}