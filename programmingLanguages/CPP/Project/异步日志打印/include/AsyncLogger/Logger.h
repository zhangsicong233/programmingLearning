/**
 * @file Logger.h
 * @brief 异步日志器类头文件
 *
 * 实现一个基于线程池的异步日志系统，支持格式化输出（类似Python的str.format风格）。
 * 日志消息会被格式化为字符串，然后通过线程池异步写入文件，避免阻塞主线程。
 * 日志器使用shared_ptr管理生命周期，确保在异步任务中对象安全。
 */

#pragma once

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <utility>
#include <vector>

#include "ThreadPool.h"

/**
 * @brief 辅助函数：将任意类型转换为字符串
 * @tparam T 输入类型（可流输出）
 * @param msg 待转换的值
 * @return std::string 转换后的字符串
 *
 * 使用std::ostringstream进行转换，支持所有重载了operator<<的类型。
 */
template <typename T>
std::string to_string_helper(T&& msg) {
  std::ostringstream oss;
  oss << std::forward<T>(msg);
  return oss.str();
}

/**
 * @class Logger
 * @brief 异步日志器类
 *
 * 提供格式化日志接口，内部使用线程池异步写入文件。
 * 继承自std::enable_shared_from_this，以便在lambda中安全地传递shared_ptr。
 * 日志文件以追加模式打开，线程安全（每个日志写入受互斥锁保护）。
 */
class Logger : public std::enable_shared_from_this<Logger> {
 public:
  /**
   * @brief 创建Logger实例的工厂方法
   * @param filename 日志文件路径
   * @return std::shared_ptr<Logger> 指向新Logger实例的shared_ptr
   * @throw std::runtime_error 如果无法打开日志文件
   *
   * 由于构造函数是私有的，使用此静态方法创建实例。
   * 返回的shared_ptr可以安全地用于多线程环境。
   */
  static std::shared_ptr<Logger> create(const std::string& filename);

  /**
   * @brief 记录一条格式化日志
   * @tparam Args 参数类型包
   * @param format 格式字符串，使用"{}"作为占位符
   * @param args 替换占位符的参数
   *
   * 示例：
   * @code
   * logger->log("User {} performed {} in {} seconds.", 42, "login", 3.5);
   * @endcode
   *
   * 格式化消息后，通过线程池提交写文件任务，实现异步写入。
   */
  template <typename... Args>
  void log(const std::string& format, Args&&... args) {
    // 格式化消息
    std::string formatted_msg =
        formatMessage(format, std::forward<Args>(args)...);
    // 获取线程池单例并提交写任务
    ThreadPool::getInstance().enqueue(
        [self = shared_from_this(), msg = std::move(formatted_msg)]() {
          self->writeLog(msg);
        });
  }

  /**
   * @brief 析构函数
   *
   * 关闭日志文件（如果打开）。由于使用了shared_ptr，文件流会在所有引用释放后自动关闭。
   */
  ~Logger();

 private:
  /**
   * @brief 私有构造函数
   * @param filename 日志文件路径
   * @throw std::runtime_error 如果无法打开日志文件
   *
   * 以追加模式打开文件，并初始化文件流和互斥体的shared_ptr。
   */
  explicit Logger(const std::string& filename);

  /**
   * @brief 将格式化后的消息写入文件
   * @param msg 待写入的日志消息
   *
   * 由线程池调用，受互斥锁保护，确保多线程下写入顺序和安全。
   */
  void writeLog(const std::string& msg);

  /**
   * @brief 格式化消息，将占位符替换为实际参数
   * @tparam Args 参数类型包
   * @param format 格式字符串
   * @param args 参数
   * @return std::string 格式化后的字符串
   *
   * 格式字符串中的"{}"将被依次替换为args的字符串表示。
   * 如果占位符数量少于参数，多余参数会被追加到末尾。
   * 如果占位符数量多于参数，多余的占位符保持原样"{}"。
   */
  template <typename... Args>
  std::string formatMessage(const std::string& format, Args&&... args) {
    std::vector<std::string> arg_strings = {
        to_string_helper(std::forward<Args>(args))...};

    std::ostringstream oss;
    std::size_t arg_index = 0;
    std::size_t pos = 0;
    size_t placeholder = format.find("{}", pos);
    while (placeholder != std::string::npos) {
      oss << format.substr(pos, placeholder - pos);
      if (arg_index < arg_strings.size()) {
        oss << arg_strings[arg_index++];
      } else {
        oss << "{}";  // 占位符多于参数，保留原样
      }

      pos = placeholder + 2;
      placeholder = format.find("{}", pos);
    }

    oss << format.substr(pos);

    // 如果参数多于占位符，将剩余参数追加到末尾
    while (arg_index < arg_strings.size()) {
      oss << arg_strings[arg_index++];
    }

    return oss.str();
  }

  std::shared_ptr<std::ofstream> _log_file;  ///< 文件输出流，使用shared_ptr共享
  std::shared_ptr<std::mutex>
      _file_mutex;  ///< 保护文件写入的互斥体，使用shared_ptr共享
};
