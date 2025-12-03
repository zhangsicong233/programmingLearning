#pragma once

#include <boost/asio.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>

class CServer;

class MsgNode {
  friend class CSession;

 public:
  MsgNode(char* msg, int max_len) {
    _data = new char[max_len];
    memcpy(_data, msg, max_len);
  }

  ~MsgNode() { delete[] _data; }

 private:
  int _cur_len;
  int _max_len;
  char* _data;
};

class CSession : public std::enable_shared_from_this<CSession> {
 public:
  CSession(boost::asio::io_context& ioc, CServer* server)
      : _socket(ioc), _server(server) {
    boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
    _uuid = boost::uuids::to_string(a_uuid);
  }

  boost::asio::ip::tcp::socket& Socket() { return _socket; }

  void Start();
  void Send(char* msg, int max_length);
  std::string& GetUuid();

 private:
  boost::asio::ip::tcp::socket _socket;
  enum { _max_length = 1024 };
  char _data[_max_length];
  CServer* _server;
  std::string _uuid;
  std::queue<std::shared_ptr<MsgNode> > _send_que;
  std::mutex _send_lock;

  void HandleRead(const boost::system::error_code& error,
                  size_t bytes_transferred,
                  std::shared_ptr<CSession> _self_shared);
  void HandleWrite(const boost::system::error_code& error,
                   std::shared_ptr<CSession> _self_shared);
};
