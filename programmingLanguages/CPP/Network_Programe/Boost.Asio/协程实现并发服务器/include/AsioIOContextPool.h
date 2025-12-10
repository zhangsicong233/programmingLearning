#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <vector>

class AsioIOContextPool {
 public:
  using IOContext = boost::asio::io_context;
  using Work = boost::asio::io_context::work;
  using WorkPtr = std::unique_ptr<Work>;

  AsioIOContextPool(const AsioIOContextPool&) = delete;
  AsioIOContextPool& operator=(const AsioIOContextPool&) = delete;

  ~AsioIOContextPool();

  static AsioIOContextPool& GetInstance();

  boost::asio::io_context& GetIOContext();

  void Stop();

 private:
  AsioIOContextPool(std::size_t size = std::thread::hardware_concurrency());

  std::vector<IOContext> _ioContexts;
  std::vector<WorkPtr> _works;
  std::vector<std::thread> _threads;

  std::size_t _nextIOContext;
};
