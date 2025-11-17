#pragma once
#include <iostream>

#include "Worker.h"

class Manager : public Worker {
 public:
  Manager(int id, std::string name, int deptId);

  void showInfo() override;

  std::string getDeptName() override;
};