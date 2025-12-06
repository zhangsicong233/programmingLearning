#pragma once

#include <boost/asio.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>

constexpr int MAX_LENGTH = 1024 * 2;
constexpr int HEAD_LENGTH = 2;

class CServer;

class MsgNode {
  friend class CSession;

 public:
  MsgNode(char* msg, short max_len)
      : _total_len(max_len + HEAD_LENGTH), _cur_len(0) {
    _data = new char[_total_len + 1]();
    memcpy(_data, &max_len, HEAD_LENGTH);
    memcpy(_data + HEAD_LENGTH, msg, max_len);
    _data[_total_len] = '\0';
  }

  MsgNode(short max_len) : _total_len(max_len), _cur_len(0) {
    _data = new char[_total_len + 1]();
  }

  ~MsgNode() { delete[] _data; }

  void Clear() {
    ::memset(_data, 0, _total_len);
    _cur_len = 0;
  }

 private:
  short _total_len;
  short _cur_len;
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
  // 收到的消息结构
  std::shared_ptr<MsgNode> _recv_msg_node;
  bool _b_head_parse;
  // 收到的头部结构
  std::shared_ptr<MsgNode> _recv_head_node;

  void HandleRead(const boost::system::error_code& error,
                  size_t bytes_transferred,
                  std::shared_ptr<CSession> _self_shared);
  void HandleWrite(const boost::system::error_code& error,
                   std::shared_ptr<CSession> _self_shared);
};
