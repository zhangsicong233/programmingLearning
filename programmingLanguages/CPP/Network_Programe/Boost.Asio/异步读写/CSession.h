#pragma once

#include <boost/asio.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

#define MAX_LENGTH 1024 * 2
#define HEAD_LENGTH 2
#define MAX_SENDQUE 1000

class CServer;

class MsgNode {
  friend class CSession;

 public:
  MsgNode(char* msg, short max_len)
      : _total_len(max_len + HEAD_LENGTH), _cur_len(0) {
    _data = new char[_total_len + 1]();
    // 转为网络字节序
    int max_len_host =
        boost::asio::detail::socket_ops::host_to_network_short(max_len);
    memcpy(_data, &max_len_host, HEAD_LENGTH);
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
  short _cur_len;
  short _total_len;
  char* _data;
};

class CSession : public std::enable_shared_from_this<CSession> {
 public:
  CSession(boost::asio::io_context& ioc, CServer* server);

  boost::asio::ip::tcp::socket& Socket() { return _socket; }
  void Start();
  void Send(char* msg, int max_length);
  void Close();
  std::string& GetUuid();

  ~CSession();

 private:
  boost::asio::ip::tcp::socket _socket;
  enum { _max_length = MAX_LENGTH };
  char _data[_max_length];

  CServer* _server;
  std::string _uuid;

  std::mutex _send_lock;
  std::queue<std::shared_ptr<MsgNode>> _send_que;

  bool _b_head_parse;
  // 收到的头部结构
  std::shared_ptr<MsgNode> _recv_head_node;
  // 收到的消息结构
  std::shared_ptr<MsgNode> _recv_msg_node;

  bool _b_close;

  void HandleRead(const boost::system::error_code& error,
                  size_t bytes_transferred,
                  std::shared_ptr<CSession> self_shared);
  void HandleWrite(const boost::system::error_code& error,
                   std::shared_ptr<CSession> self_shared);
};
