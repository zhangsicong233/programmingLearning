#include "AsioIOContextPool.h"

AsioIOContextPool::AsioIOContextPool(std::size_t size)
    : _ioContexts(size),
      _works(size),
      _nextIOContext(0),
      _stopped(false) {
  for (std::size_t i = 0; i < size; ++i) {
    _works[i] = std::unique_ptr<Work>(new Work(_ioContexts[i]));
  }

  // 遍历多个 io_context, 创建多个线程，每个线程内部启动 io_context
  for (std::size_t i = 0; i < _ioContexts.size(); ++i) {
    _threads.emplace_back([this, i]() { _ioContexts[i].run(); });
  }
}

AsioIOContextPool::~AsioIOContextPool() {
  std::cout << "AsioIOContextPool destruct" << std::endl;
  stop();
}

boost::asio::io_context& AsioIOContextPool::GetIOContext() {
  auto& context = _ioContexts[_nextIOContext++];
  if (_nextIOContext == _ioContexts.size()) {
    _nextIOContext = 0;
  }

  return context;
}

void AsioIOContextPool::stop() {
  if (_stopped.exchange(true)) {
    return; // already stopped
  }

  // 重置 work 对象，允许 io_context 自然退出
  for (auto& work : _works) {
    work.reset();
  }

  // 等待所有线程结束
  for (auto& t : _threads) {
    if (t.joinable()) {
      t.join();
    }
  }
}