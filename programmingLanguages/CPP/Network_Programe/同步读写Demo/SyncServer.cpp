#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/detail/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include <set>

constexpr int MAX_LENGTH = 1024;
typedef std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;
std::set<std::shared_ptr<std::thread>> thread_set;

// 服务端处理客户端连接
void session(socket_ptr sock) {
  try {
    for (;;) {
      char data[MAX_LENGTH];
      memset(data, '\0', MAX_LENGTH);
      boost::system::error_code error;
      // std::size_t length = boost::asio::read(sock, boost::asio::buffer(data,
      // MAX_LENGTH), error);
      std::size_t length =
          sock->read_some(boost::asio::buffer(data, MAX_LENGTH), error);
      if (error == boost::asio::error::eof) {
        std::cout << "Connection closed by peer" << std::endl;

        break;
      } else if (error) {
        throw boost::system::system_error(error);
      }

      std::cout << "receive from "
                << sock->remote_endpoint().address().to_string() << std::endl;
    std:
      std::cout << "receive message is " << data << std::endl;

      // 回传给对方
      boost::asio::write(*sock, boost::asio::buffer(data, length));
    }
  } catch (std::exception& e) {
    std::cerr << "Exception in thread: " << e.what() << '\n' << std::endl;
  }
}

void server(boost::asio::io_context& io_context, unsigned short port) {
  boost::asio::ip::tcp::acceptor acceptor(
      io_context,
      boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
  for (;;) {
    socket_ptr socket(new boost::asio::ip::tcp::socket(io_context));
    acceptor.accept(*socket);

    auto t = std::make_shared<std::thread>(session, socket);
    thread_set.insert(t);
  }
}

int main() {
  try {
    boost::asio::io_context ioc;
    server(ioc, 10086);
    for (auto& t : thread_set) {
      t->join();
    }
  } catch (std::exception& e) {
    std::cerr << "Exception " << e.what() << std::endl;
  }

  return 0;
}