#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <string>

#include "const.h"

class MsgNode {
 public:
  MsgNode(short max_len);

  void Clear();

  ~MsgNode();

  short _cur_len;
  short _total_len;
  char* _data;
};

class RecvNode : public MsgNode {
 public:
  RecvNode(short max_len, short msg_id);

  short _msg_id;
};

class SendNode : public MsgNode {
 public:
  SendNode(const char* msg, int max_len, short msg_id);

  short _msg_id;
};
