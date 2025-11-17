#pragma once
#include <iostream>

#include "Worker.h"

class Boss : public Worker {
 public:
  Boss(int id, std::string name, int dId);

  void showInfo() override;

  std::string getDeptName() override;
};