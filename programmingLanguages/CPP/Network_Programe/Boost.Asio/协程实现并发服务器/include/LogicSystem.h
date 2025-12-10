#pragma once

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

#include <condition_variable>
#include <functional>
#include <map>
#include <queue>
#include <thread>

#include "CSession.h"
#include "const.h"

using FunCallBack = std::function<void(std::shared_ptr<CSession>, const short&,
                                       const std::string&)>;

class LogicSystem {
 public:
  LogicSystem(const LogicSystem&) = delete;
  LogicSystem& operator=(const LogicSystem&) = delete;

  ~LogicSystem();

  static LogicSystem& GetInstance();

  void PostMsgToQue(std::shared_ptr<LogicNode> msg);

 private:
  LogicSystem();

  std::thread _worker_thread;
  std::queue<std::shared_ptr<LogicNode>> _msg_que;

  std::mutex _mutex;
  std::condition_variable _consume;

  bool _b_stop;

  std::map<short, FunCallBack> _fun_callbacks;

  void DealMsg();
  void RegisterCallBacks();
  void HelloWorldCallBack(std::shared_ptr<CSession> session,
                          const short& msg_id, const std::string& msg_data);
};