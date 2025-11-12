#include <iostream>

int main() {
  // 引用基本语法
  // 数据类型& 别名 = 原名
  int a = 10;
  // 创建引用
  int& b = a;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  b = 100;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  return 0;
}