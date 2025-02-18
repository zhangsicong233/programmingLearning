#include <iostream>

int main() {
  // 1、前置递增
  int a = 10;
  ++a;  // 使变量 +1
  std::cout << "a = " << a << std::endl;

  // 2、后置递增
  int b = 10;
  b++;  // 使变量 +1
  std::cout << "b = " << b << std::endl;

  // 3、前置和后置的区别
  // 前置：先变量 +1 再进行表达式运算
  int a2 = 10;
  int b2 = ++a2 * 10;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "b2 = " << b2 << std::endl;

  // 后置：先进行表达式运算 再变量 +1
  int a3 = 10;
  int b3 = a3++ * 10;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "b3 = " << b3 << std::endl;

  return 0;
}