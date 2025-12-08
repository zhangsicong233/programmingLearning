#include <boost/asio.hpp>
#include <iostream>

#include "CServer.h"

int main() {
  try {
    boost::asio::io_context ioc;

    CServer s(ioc, 10086);
    ioc.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}