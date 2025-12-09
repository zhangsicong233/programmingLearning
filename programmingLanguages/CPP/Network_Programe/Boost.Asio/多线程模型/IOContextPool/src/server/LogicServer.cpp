#include <condition_variable>
#include <csignal>
#include <iostream>
#include <mutex>
#include <thread>

#include "AsioIOContextPool.h"
#include "CServer.h"

int main() {
  try {
    auto pool = AsioIOContextPool::GetInstance();

    boost::asio::io_context ioc;

    boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
    signals.async_wait([&ioc, pool](auto, auto) {
      ioc.stop();

      pool->Stop();
    });

    CServer s(ioc, 10086);

    ioc.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << endl;
  }

  return 0;
}