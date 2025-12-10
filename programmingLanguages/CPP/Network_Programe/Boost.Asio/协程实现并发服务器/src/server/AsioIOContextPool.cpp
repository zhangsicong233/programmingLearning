#include "AsioIOContextPool.h"

#include <iostream>

AsioIOContextPool::AsioIOContextPool(std::size_t size)
    : _ioContexts(size), _works(size), _nextIOContext(0) {
  for (std::size_t i = 0; i < size; ++i) {
    _works[i] = std::make_unique<Work>(_ioContexts[i]);

    // 为每一个 io_context 创建线程, 并启动 io_context
    _threads.emplace_back([this, i]() { _ioContexts[i].run(); });
  }
}

AsioIOContextPool::~AsioIOContextPool() {
  std::cout << "AsioIOContextPool destruct" << std::endl;
}

AsioIOContextPool& AsioIOContextPool::GetInstance() {
  static AsioIOContextPool instance;

  return instance;
}

boost::asio::io_context& AsioIOContextPool::GetIOContext() {
  auto& context = _ioContexts[_nextIOContext++];

  _nextIOContext %= _ioContexts.size();

  return context;
}

void AsioIOContextPool::Stop() {
  for (auto& work : _works) {
    work->get_io_context().stop();

    work.reset();
  }

  for (auto& t : _threads) {
    t.join();
  }
}