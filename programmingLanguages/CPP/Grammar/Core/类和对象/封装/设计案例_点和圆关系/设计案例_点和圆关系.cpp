#include <cmath>
#include <iostream>

#include "Circle.h"
#include "Point.h"

// 点类
/*
class Point {
 public:
  void setX(int x) { this->m_X = x; };
  int getX() const { return this->m_X; }

  void setY(int y) { this->m_Y = y; }
  int getY() const { return this->m_Y; }

 private:
  int m_X;  // x 坐标
  int m_Y;  // y 坐标
};
*/

// 圆类
/*
class Circle {
 public:
  void setR(double r) { this->m_R = r; }
  double getR() const { return this->m_R; }

  void setCenter(Point center) { this->m_Center = center; }
  Point getCenter() const { return this->m_Center; }

  void isInCircle(const Point& pnt) {
    // 计算两点之间距离平方
    double distance = std::pow((this->m_Center.getX() - pnt.getX()), 2) +
                      std::pow((this->m_Center.getY() - pnt.getY()), 2);
    // 计算半径平方
    double Rdistance = std::pow(this->m_R, 2);

    // 判断关系
    if (distance < Rdistance) {
      std::cout << "点在圆内" << std::endl;
    } else if (distance == Rdistance) {
      std::cout << "点在圆上" << std::endl;
    } else {
      std::cout << "点在圆外" << std::endl;
    }
  }

 private:
  Point m_Center;  // 圆心
  double m_R;      // 半径
};
*/

int main() {
  // 创建圆
  Point center;
  center.setX(10);
  center.setY(0);

  Circle c;
  c.setR(10);
  c.setCenter(center);

  // 创建点
  Point p1;
  p1.setX(10);
  p1.setY(10);

  Point p2;
  p2.setX(10);
  p2.setY(5);

  Point p3;
  p3.setX(10);
  p3.setY(20);

  // 判断关系
  std::cout << "p1：";
  c.isInCircle(p1);

  std::cout << "p2：";
  c.isInCircle(p2);

  std::cout << "p3：";
  c.isInCircle(p3);

  return 0;
}