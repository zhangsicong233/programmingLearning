#pragma once

#include <iostream>

// 点类
class Point {
 public:
  void setX(int x);
  int getX() const;

  void setY(int y);
  int getY() const;

 private:
  int m_X;  // x 坐标
  int m_Y;  // y 坐标
};