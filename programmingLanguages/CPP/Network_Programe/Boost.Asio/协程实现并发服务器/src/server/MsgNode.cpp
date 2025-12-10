#include "MsgNode.h"

MsgNode::MsgNode(short max_len) : _cur_len(0), _total_len(max_len) {
  _data = new char[_total_len + 1];
  _data[_total_len] = '\0';
}

void MsgNode::Clear() {
  ::memset(_data, 0, _total_len);

  _cur_len = 0;
}

MsgNode::~MsgNode() {
  std::cout << "destruct MsgNode" << std::endl;

  delete[] _data;
}

RecvNode::RecvNode(short max_len, short msg_id)
    : MsgNode(max_len), _msg_id(msg_id) {}

SendNode::SendNode(const char* msg, int max_len, short msg_id)
    : MsgNode(max_len + HEAD_TOTAL_LEN), _msg_id(msg_id) {
  // 先发送 id, 转为网络字节序
  short msg_id_net =
      boost::asio::detail::socket_ops::host_to_network_short(msg_id);
  memcpy(_data, &msg_id_net, HEAD_ID_LEN);

  // 在发送消息长度, 转为网络字节序
  short msg_len_net =
      boost::asio::detail::socket_ops::host_to_network_short(max_len);
  memcpy(_data + HEAD_ID_LEN, &msg_len_net, HEAD_DATA_LEN);

  // 最后发送消息
  memcpy(_data + HEAD_TOTAL_LEN, msg, max_len);
}