#include "CSession.h"

#include <iostream>

#include "CServer.h"

CSession::CSession(boost::asio::io_context& ioc, CServer* server)
    : _socket(ioc), _server(server), _b_head_parse(false), _b_close(false) {
  boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
  _uuid = boost::uuids::to_string(a_uuid);

  _recv_head_node = std::make_shared<MsgNode>(HEAD_LENGTH);
  _recv_msg_node = nullptr;
}

void CSession::Start() {
  std::cout << "CSession started, waiting for data..." << std::endl;

  memset(_data, 0, _max_length);

  _socket.async_read_some(
      boost::asio::buffer(_data, _max_length),
      std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                std::placeholders::_2, shared_from_this()));
}

void CSession::Send(char* msg, int max_length) {
  bool pending = false;
  std::unique_lock<std::mutex> lock(_send_lock);

  int send_que_size = _send_que.size();
  if (send_que_size > MAX_SENDQUE) {
    std::cout << "session: " << _uuid << " send que fulled, size is "
              << MAX_SENDQUE << std::endl;

    return;
  }

  // 确保 max_length 在合理范围内
  if (max_length <= 0 || max_length > MAX_LENGTH) {
    std::cout << "Invalid message length: " << max_length << std::endl;

    return;
  }

  if (_send_que.size() > 0) {
    pending = true;
  }

  // 创建消息节点
  std::shared_ptr<MsgNode> msg_node =
      std::make_shared<MsgNode>(msg, max_length);
  _send_que.push(msg_node);

  if (pending) {
    return;
  }

  // 发送数据
  std::cout << "Sending response, length: " << max_length << std::endl;
  boost::asio::async_write(
      _socket, boost::asio::buffer(msg_node->_data, msg_node->_total_len),
      std::bind(&CSession::HandleWrite, this, std::placeholders::_1,
                shared_from_this()));
}

void CSession::Close() {
  _socket.close();

  _b_close = true;
}

std::string& CSession::GetUuid() { return _uuid; }

CSession::~CSession() { std::cout << "session destruct" << std::endl; }

void CSession::HandleRead(const boost::system::error_code& error,
                          size_t bytes_transferred,
                          std::shared_ptr<CSession> shared_self) {
  if (!error) {
    // 已经移动的字节数
    int copy_len = 0;
    while (bytes_transferred > 0) {
      if (!_b_head_parse) {
        // 收到的数据不足头部大小
        if (bytes_transferred + _recv_head_node->_cur_len < HEAD_LENGTH) {
          memcpy(_recv_head_node->_data + _recv_head_node->_cur_len,
                 _data + copy_len, bytes_transferred);
          _recv_head_node->_cur_len += bytes_transferred;

          ::memset(_data, 0, MAX_LENGTH);
          _socket.async_read_some(
              boost::asio::buffer(_data, MAX_LENGTH),
              std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                        std::placeholders::_2, shared_self));

          return;
        }

        // 收到的数据比头部多
        // 头部剩余未复制的长度
        int head_remain = HEAD_LENGTH - _recv_head_node->_cur_len;
        memcpy(_recv_head_node->_data + _recv_head_node->_cur_len,
               _data + copy_len, head_remain);

        // 更新已处理的data长度和剩余未处理的长度
        copy_len += head_remain;
        bytes_transferred -= head_remain;

        // 获取头部数据
        short data_len = 0;
        memcpy(&data_len, _recv_head_node->_data, HEAD_LENGTH);

        // 网络字节序转化为本地字节序
        data_len =
            boost::asio::detail::socket_ops::network_to_host_short(data_len);
        std::cout << "converted data_len is " << data_len << std::endl;

        // 头部长度非法
        if (data_len > MAX_LENGTH) {
          std::cout << "invalid data length is " << data_len << std::endl;
          _server->ClearSession(_uuid);

          return;
        }

        _recv_msg_node = std::make_shared<MsgNode>(data_len);

        // 头部处理完成
        _b_head_parse = true;

        continue;
      }

      // 已经处理完头部，处理消息数据
      // 剩余消息长度
      int remain_msg = _recv_msg_node->_total_len - _recv_msg_node->_cur_len;

      // 如果当前接收到的数据不够一条完整消息
      if (bytes_transferred < remain_msg) {
        memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len,
               _data + copy_len, bytes_transferred);
        _recv_msg_node->_cur_len += bytes_transferred;

        ::memset(_data, 0, MAX_LENGTH);
        _socket.async_read_some(
            boost::asio::buffer(_data, MAX_LENGTH),
            std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                      std::placeholders::_2, shared_self));

        return;
      }

      // 当前接收到的数据足够一条完整消息
      memcpy(_recv_msg_node->_data + _recv_msg_node->_cur_len, _data + copy_len,
             remain_msg);
      _recv_msg_node->_cur_len += remain_msg;

      copy_len += remain_msg;
      bytes_transferred -= remain_msg;

      // 消息处理完成，添加结束符并输出
      _recv_msg_node->_data[_recv_msg_node->_total_len] = '\0';
      std::cout << "receive data is " << _recv_msg_node->_data << std::endl;

      // 处理接收到的完整消息
      Send(_recv_msg_node->_data, _recv_msg_node->_total_len);

      // 重置状态，准备处理下一条消息
      _b_head_parse = false;
      _recv_head_node->Clear();

      // 如果还有剩余数据，继续循环处理
      if (bytes_transferred <= 0) {
        // 数据已处理完，继续读取
        ::memset(_data, 0, MAX_LENGTH);
        _socket.async_read_some(
            boost::asio::buffer(_data, MAX_LENGTH),
            std::bind(&CSession::HandleRead, this, std::placeholders::_1,
                      std::placeholders::_2, shared_self));

        return;
      }

      // 还有剩余数据，可能是下一条消息，继续循环处理
      continue;
    }
  } else {
    std::cout << "handle read failed, error is " << error.what() << std::endl;

    Close();

    _server->ClearSession(_uuid);
  }
}

void CSession::HandleWrite(const boost::system::error_code& error,
                           std::shared_ptr<CSession> self_shared) {
  if (!error) {
    std::unique_lock<std::mutex> lock(_send_lock);
    // 获取刚发送的消息
    auto sent_msg = _send_que.front();
    short sent_len = 0;
    memcpy(&sent_len, sent_msg->_data, HEAD_LENGTH);
    sent_len = boost::asio::detail::socket_ops::network_to_host_short(sent_len);
    std::cout << "Successfully sent message, length: " << sent_len << std::endl;

    _send_que.pop();
    if (!_send_que.empty()) {
      auto& msgnode = _send_que.front();
      boost::asio::async_write(
          _socket, boost::asio::buffer(msgnode->_data, msgnode->_total_len),
          std::bind(&CSession::HandleWrite, this, std::placeholders::_1,
                    self_shared));
    }
  } else {
    std::cout << "handle write failed, error is " << error.what() << std::endl;

    _server->ClearSession(_uuid);
  }
}
