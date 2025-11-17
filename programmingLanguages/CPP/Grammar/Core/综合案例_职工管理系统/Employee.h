#pragma once
#include <iostream>

#include "Worker.h"

class Employee : public Worker {
 public:
  Employee(int id, std::string name, int dId);

  void showInfo() override;

  std::string getDeptName() override;
};