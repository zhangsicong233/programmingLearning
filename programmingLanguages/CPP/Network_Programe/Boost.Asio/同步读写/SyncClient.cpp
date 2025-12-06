#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/impl/read.hpp>
#include <boost/asio/impl/write.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/system/detail/error_code.hpp>
#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>

constexpr int MAX_LENGTH = 1024;

int main() {
  try {
    // 创建上下文服务
    boost::asio::io_context ioc;

    // 构造一个 endpoint
    boost::asio::ip::tcp::endpoint remote_ep(
        boost::asio::ip::make_address("127.0.0.1"), 10086);

    boost::asio::ip::tcp::socket sock(ioc);
    boost::system::error_code error = boost::asio::error::host_not_found;
    sock.connect(remote_ep, error);
    if (error) {
      std::cout << "Connect failed, code is: " << error.value()
                << ". error msg is: " << error.message() << std::endl;

      return 0;
    }

    std::cout << "Enter message: ";

    // 访问服务端
    char request[MAX_LENGTH];
    std::cin.getline(request, MAX_LENGTH);

    std::size_t request_length = strlen(request);
    boost::asio::write(sock, boost::asio::buffer(request, request_length));

    // 获取服务端的返回
    char reply[MAX_LENGTH];
    std::size_t reply_length =
        boost::asio::read(sock, boost::asio::buffer(reply, request_length));

    std::cout << "Reply is: ";
    std::cout.write(reply, reply_length);
    std::cout << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}