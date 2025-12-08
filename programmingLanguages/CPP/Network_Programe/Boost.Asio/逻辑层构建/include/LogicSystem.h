#pragma once

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

#include <condition_variable>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <thread>

#include "CSession.h"
#include "Singleton.hpp"
#include "const.h"

using FunCallBack =
    std::function<void(std::shared_ptr<CSession>, const short&, const string&)>;

class LogicSystem : public Singleton<LogicSystem> {
  friend class Singleton<LogicSystem>;

 public:
  ~LogicSystem();

  void PostMsgToQue(std::shared_ptr<LogicNode> msg);

 private:
  LogicSystem();

  std::mutex _mutex;
  std::condition_variable _consume;
  std::queue<std::shared_ptr<LogicNode>> _msg_que;
  std::thread _worker_thread;
  bool _b_stop;
  std::map<short, FunCallBack> _fun_callback;

  void RegisterCallBacks();
  void HelloWordCallBack(std::shared_ptr<CSession> session, const short& msg_id,
                         const string& msg_data);
  void DealMsg();
};