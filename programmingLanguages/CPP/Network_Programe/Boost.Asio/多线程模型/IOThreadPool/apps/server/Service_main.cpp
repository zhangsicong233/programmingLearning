#include <csignal>
#include <iostream>
#include <mutex>
#include <thread>

#include "AsioThreadPool.h"
#include "CServer.h"
#include "LogicSystem.h"
#include "Singleton.h"
using namespace std;

int main() {
  try {
    auto pool = AsioThreadPool::GetInstance();
    boost::asio::io_context io_context;
    boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
    signals.async_wait([pool, &io_context](auto, auto) {
      io_context.stop();
      pool->Stop();
    });

    CServer s(pool->GetIOService(), 10086);

    // ˳io_context
    io_context.run();
    std::cout << "server exited " << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << endl;
  }
}