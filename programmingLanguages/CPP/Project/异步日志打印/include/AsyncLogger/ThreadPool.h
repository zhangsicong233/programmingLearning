/**
 * @file ThreadPool.h
 * @brief 线程池类（单例模式）头文件
 *
 * 实现一个通用的线程池，支持提交任意任务，使用条件变量和互斥锁实现线程同步。
 * 线程池采用单例模式，确保整个应用程序中只有一个线程池实例，避免资源浪费。
 * 支持动态调整线程数量（通过构造函数参数），并可在程序结束时自动回收资源。
 */

#pragma once

#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

/**
 * @class ThreadPool
 * @brief 线程池类，单例模式
 *
 * 提供任务队列，多个工作线程从队列中取出任务并执行。
 * 支持任意可调用对象（函数、lambda、成员函数等）作为任务。
 * 线程安全，可在多线程环境下安全地提交任务。
 */
class ThreadPool {
 public:
  /**
   * @brief 获取线程池单例实例
   * @param numThreads 线程数量，默认为 5
   * @return ThreadPool& 线程池实例的引用
   *
   * 使用局部静态变量实现线程安全的单例（C++11保证静态局部变量初始化线程安全）。
   * 首次调用时创建实例，后续调用返回同一实例。
   */
  static ThreadPool& getInstance(int numThreads = 5);

  // 禁止拷贝和移动，确保单例唯一性
  ThreadPool(const ThreadPool&) = delete;
  ThreadPool& operator=(const ThreadPool&) = delete;

  /**
   * @brief 向线程池提交一个任务
   * @tparam F 可调用对象类型
   * @tparam Args 参数类型包
   * @param f 可调用对象（函数、lambda等）
   * @param args 传递给可调用对象的参数
   *
   * 任务会被包装成一个std::function<void()>，并放入任务队列。
   * 如果有空闲线程，该任务会被立即执行；否则等待线程空闲。
   * 使用完美转发确保参数类型和值类别不变。
   */
  template <typename F, typename... Args>
  void enqueue(F&& f, Args&&... args) {
    // 使用lambda完美转发参数，避免使用std::bind（C++20起支持lambda包展开）
    auto task = [func = std::forward<F>(f),
                 ... args = std::forward<Args>(args)]() mutable {
      func(std::forward<Args>(args)...);
    };

    {
      std::unique_lock<std::mutex> lock(_mtx);
      _tasks.emplace(std::move(task));
    }

    _condition.notify_one();  // 通知一个等待的线程有新任务
  }

  /**
   * @brief 获取当前线程池中的线程数量
   * @return size_t 线程数
   */
  size_t threadCount() const;

  /**
   * @brief 停止线程池
   *
   * 设置停止标志，唤醒所有线程，等待所有线程结束并清空线程列表。
   * 析构函数会自动调用此方法，也可手动提前停止。
   */
  void shutdown();

  /**
   * @brief 析构函数
   *
   * 自动调用shutdown()，确保所有资源被正确释放。
   */
  ~ThreadPool();

 private:
  /**
   * @brief 私有构造函数
   * @param numThreads 线程数量
   *
   * 创建指定数量的工作线程，每个线程执行worker循环。
   */
  explicit ThreadPool(int numThreads);

  std::vector<std::thread> _threads;         ///< 工作线程容器
  std::queue<std::function<void()>> _tasks;  ///< 任务队列

  std::mutex _mtx;                     ///< 保护任务队列的互斥锁
  std::condition_variable _condition;  ///< 条件变量，用于线程等待/通知

  bool _stop;  ///< 停止标志，为true时线程池停止接受新任务
};