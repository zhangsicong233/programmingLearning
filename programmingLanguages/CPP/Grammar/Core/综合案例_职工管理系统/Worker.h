#pragma once
#include <iostream>

class Worker {
public:
  virtual void showInfo() = 0;

  virtual std::string getDeptName() = 0;

  // 添加虚析构函数解决 delete 抽象类的问题
  virtual ~Worker() = default;

  int m_Id;
  std::string m_Name;
  int m_DeptId;
};