#pragma once

#include <boost/asio.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <memory>
#include <mutex>
#include <queue>

#include "MsgNode.h"
#include "const.h"

class CServer;

class CSession : public std::enable_shared_from_this<CSession> {
 public:
  CSession(boost::asio::io_context& io_context, CServer* server);

  boost::asio::ip::tcp::socket& GetSocket();
  void Start();
  std::string& GetUuid();
  void Send(std::string msg, short msgid);
  void Send(const char* msg, short max_length, short msgid);
  void Close();

  ~CSession();

 private:
  boost::asio::io_context& _io_context;
  CServer* _server;
  boost::asio::ip::tcp::socket _socket;

  std::string _uuid;

  bool _b_close;

  std::mutex _send_lock;
  std::queue<std::shared_ptr<SendNode>> _send_que;
  std::shared_ptr<RecvNode> _recv_msg_node;
  std::shared_ptr<MsgNode> _recv_head_node;

  void HandleWrite(const boost::system::error_code& error,
                   std::shared_ptr<CSession> shared_self);
};

class LogicNode {
 public:
  LogicNode(std::shared_ptr<CSession> session,
            std::shared_ptr<RecvNode> recvnode);

  std::shared_ptr<CSession> _session;
  std::shared_ptr<RecvNode> _recvnode;
};