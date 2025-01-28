#include <iostream>

int main() {
  // 默认情况下，输出一个小数，会显示出 6 位有效数字
  // 单精度 float
  float f1 = 3.1415926f;
  std::cout << "f1 = " << f1 << std::endl;

  // 双精度 double
  double d1 = 3.1415926;
  std::cout << "d1 = " << d1 << std::endl;

  // 统计 float 和 double 所占用内存空间
  std::cout << "float 所占用的内存空间为：" << sizeof(float) << std::endl;
  std::cout << "double 所占用的内存空间为：" << sizeof(double) << std::endl;

  // 科学计数法
  float f2 = 3e2f;  // 3*10^2
  std::cout << "f2 = " << f2 << std::endl;

  float f3 = 3e-2f;  // 3*10^-2
  std::cout << "f3 = " << f3 << std::endl;

  return 0;
}