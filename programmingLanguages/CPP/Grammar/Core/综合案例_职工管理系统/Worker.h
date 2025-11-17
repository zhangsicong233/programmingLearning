#pragma once
#include <iostream>

class Worker {
 public:
  virtual void showInfo() = 0;

  virtual std::string getDeptName() = 0;

  int m_Id;
  std::string m_Name;
  int m_DeptId;
};