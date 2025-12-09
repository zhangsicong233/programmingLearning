#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

#include "Singleton.hpp"

class AsioIOContextPool : public Singleton<AsioIOContextPool> {
  friend Singleton<AsioIOContextPool>;

 public:
  using IOContext = boost::asio::io_context;
  using Work = boost::asio::io_context::work;
  using WorkPtr = std::unique_ptr<Work>;

  AsioIOContextPool(const AsioIOContextPool&) = delete;
  AsioIOContextPool& operator=(const AsioIOContextPool&) = delete;

  ~AsioIOContextPool();

  // 使用 round-robin 的方式返回一个 io_context
  boost::asio::io_context& GetIOContext();
  void stop();

 private:
  AsioIOContextPool(std::size_t size = std::thread::hardware_concurrency());

  std::vector<IOContext> _ioContexts;
  std::vector<WorkPtr> _works;
  std::vector<std::thread> _threads;
  std::size_t _nextIOContext;
  std::atomic<bool> _stopped;
};