#include <iostream>

// 圆周率
const double PI = 3.14;

// 设计一个圆类，求圆的周长
// 圆求周长的公式： 2 * PI * 半径
class Circle {
  // 访问权限
 public:
  // 属性
  // 半径
  double m_R;

  // 行为
  // 获取圆的周长
  double calculate_ZC() { return 2 * PI * this->m_R; }
};

int main() {
  // 通过圆类 创建具体的圆（对象）
  // 实例化（通过一个类创建一个对象的过程）
  Circle cir;
  // 给圆对象的属性进行赋值
  cir.m_R = 10;
  std::cout << "圆的周长：" << cir.calculate_ZC() << std::endl;

  return 0;
}