#pragma once

#include <boost/asio.hpp>
#include <map>
#include <memory>

class CSession;

class CServer {
 public:
  CServer(boost::asio::io_context& ioc, short port);

  void ClearSession(std::string uuid);

 private:
  boost::asio::io_context& _ioc;
  boost::asio::ip::tcp::acceptor _acceptor;
  std::map<std::string, std::shared_ptr<CSession>> _sessions;

  void start_accept();
  void handle_accept(std::shared_ptr<CSession> new_session,
                     const boost::system::error_code& error);
};