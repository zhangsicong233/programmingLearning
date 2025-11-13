#pragma once

#include <cmath>
#include <iostream>

#include "Point.h"

// 圆类
class Circle {
 public:
  void setR(double r);
  double getR() const;

  void setCenter(Point center);
  Point getCenter() const;

  void isInCircle(const Point& pnt);

 private:
  Point m_Center;  // 圆心
  double m_R;      // 半径
};