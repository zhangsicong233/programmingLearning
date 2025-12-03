#include "CSession.h"

#include <iostream>

#include "CServer.h"

void CSession::Start() {
  memset(_data, 0, _max_length);

  _socket.async_read_some(
      boost::asio::buffer(_data, _max_length),
      std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                std::placeholders::_2, shared_from_this()));
}

void CSession::Send(char* msg, int max_length) {
  bool pending = false;
  std::unique_lock<std::mutex> lock(_send_lock);
  if (_send_que.size() > 0) {
    pending = true;
  }

  _send_que.push(std::make_shared<MsgNode>(msg, max_length));
  if (pending) {
    return;
  }

  boost::asio::async_write(
      _socket, boost::asio::buffer(msg, max_length),
      std::bind(&CSession::HandleWrite, this, std::placeholders::_1,
                shared_from_this()));
}

std::string& CSession::GetUuid() { return _uuid; }

void CSession::HandleRead(const boost::system::error_code& error,
                          size_t bytes_transferred,
                          std::shared_ptr<CSession> _self_shared) {
  if (!error) {
    std::cout << "server receive data is " << _data << std::endl;

    Send(_data, bytes_transferred);
    memset(_data, 0, _max_length);

    _socket.async_read_some(
        boost::asio::buffer(_data, _max_length),
        std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                  std::placeholders::_2, _self_shared));
  } else {
    std::cout << "read error" << std::endl;

    _server->ClearSession(_uuid);
  }
}

void CSession::HandleWrite(const boost::system::error_code& error,
                           std::shared_ptr<CSession> _self_shared) {
  if (!error) {
    std::unique_lock<std::mutex> lock(_send_lock);
    _send_que.pop();
    if (!_send_que.empty()) {
      auto& msgnode = _send_que.front();
      boost::asio::async_write(
          _socket, boost::asio::buffer(msgnode->_data, msgnode->_max_len),
          std::bind(&CSession::HandleWrite, this, std::placeholders::_1,
                    _self_shared));
    }
  } else {
    std::cout << "handle write failed, error is " << error.what() << std::endl;

    _server->ClearSession(_uuid);
  }
}
