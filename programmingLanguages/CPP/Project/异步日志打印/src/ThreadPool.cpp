/**
 * @file ThreadPool.cpp
 * @brief 线程池类（单例模式）实现文件
 *
 * 实现ThreadPool.h中声明的非模板成员函数，包括单例获取、构造函数、析构函数、
 * 线程池停止和线程数查询等功能。
 */

#include "AsyncLogger/ThreadPool.h"

/**
 * @brief 获取线程池单例实例
 * @param numThreads 线程数量，默认为4（仅在首次调用时有效）
 * @return ThreadPool& 线程池实例的引用
 *
 * 使用局部静态变量实现线程安全的单例模式，确保整个程序生命周期内只有一个线程池实例。
 * 首次调用时创建线程池，后续调用忽略numThreads参数，返回已有实例。
 */
ThreadPool& ThreadPool::getInstance(int numThreads) {
  static ThreadPool instance(numThreads);
  return instance;
}

/**
 * @brief 构造函数，创建指定数量的工作线程
 * @param numThreads 线程数量
 *
 * 初始化停止标志为false，然后创建numThreads个工作线程。
 * 每个工作线程执行一个无限循环，等待条件变量通知，从任务队列中取出任务并执行。
 * 当停止标志为true且任务队列为空时，线程退出循环。
 */
ThreadPool::ThreadPool(int numThreads) : _stop(false) {
  for (int i = 0; i < numThreads; ++i) {
    _threads.emplace_back([this]() {
      while (true) {
        std::function<void()> task;

        {
          std::unique_lock<std::mutex> lock(_mtx);
          // 等待条件：停止标志为true或任务队列非空
          _condition.wait(lock, [this]() { return _stop || !_tasks.empty(); });

          // 如果线程池已停止且任务队列为空，则线程结束
          if (_stop && _tasks.empty()) {
            return;
          }

          // 从队列中取出一个任务
          task = std::move(_tasks.front());
          _tasks.pop();
        }

        // 执行任务，注意锁已在上述作用域外释放
        task();
      }
    });
  }
}

/**
 * @brief 析构函数
 *
 * 自动调用shutdown()，确保所有工作线程正确结束并回收资源。
 */
ThreadPool::~ThreadPool() { shutdown(); }

/**
 * @brief 停止线程池
 *
 * 设置停止标志为true，唤醒所有等待的工作线程。
 * 等待所有工作线程执行完毕（join），然后清空线程容器。
 * 此函数是线程安全的，可在任何时刻调用。
 */
void ThreadPool::shutdown() {
  {
    std::unique_lock<std::mutex> lock(_mtx);
    _stop = true;
  }
  _condition.notify_all();  // 唤醒所有等待的线程
  for (auto& t : _threads) {
    if (t.joinable()) {
      t.join();  // 等待线程结束
    }
  }
  _threads.clear();  // 清空线程容器
}

/**
 * @brief 获取当前线程池中的线程数量
 * @return size_t 线程数
 *
 * 返回工作线程容器的当前大小，即线程池中活跃的线程数量。
 */
size_t ThreadPool::threadCount() const { return _threads.size(); }