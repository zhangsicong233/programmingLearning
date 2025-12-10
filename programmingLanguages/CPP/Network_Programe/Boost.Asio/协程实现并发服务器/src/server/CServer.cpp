
#include "CServer.h"

#include <iostream>

#include "AsioIOContextPool.h"

CServer::CServer(boost::asio::io_context& io_context, short port)
    : _io_context(io_context),
      _port(port),
      _acceptor(io_context, boost::asio::ip::tcp::endpoint(
                                boost::asio::ip::tcp::v4(), port)) {
  StartAccept();
}

void CServer::ClearSession(std::string uuid) {
  std::unique_lock<std::mutex> lock(_mutex);
  _sessions.erase(uuid);
}

CServer::~CServer() {}

void CServer::StartAccept() {
  auto& io_context = AsioIOContextPool::GetInstance().GetIOContext();

  std::shared_ptr<CSession> new_session =
      std::make_shared<CSession>(io_context, this);
  _acceptor.async_accept(new_session->GetSocket(),
                         std::bind(&CServer::HandleAccept, this, new_session,
                                   std::placeholders::_1));
}

void CServer::HandleAccept(std::shared_ptr<CSession> new_session,
                           const boost::system::error_code& error) {
  if (!error) {
    new_session->Start();

    std::unique_lock<std::mutex> lock(_mutex);
    _sessions.emplace(std::make_pair(new_session->GetUuid(), new_session));
  } else {
    std::cout << "session accept failed, error is " << error.what()
              << std::endl;
  }

  StartAccept();
}