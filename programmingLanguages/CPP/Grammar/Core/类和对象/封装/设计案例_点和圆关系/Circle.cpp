#include "Circle.h"

// 圆类
void Circle::setR(double r) { this->m_R = r; }
double Circle::getR() const { return this->m_R; }

void Circle::setCenter(Point center) { this->m_Center = center; }
Point Circle::getCenter() const { return this->m_Center; }

void Circle::isInCircle(const Point& pnt) {
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