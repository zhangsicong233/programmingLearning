#include <iostream>

int main() {
  int a = 10;
  // 1、引用必须初始化
  // int& b;  // 错误，必须要初始化
  int& b = a;

  // 2、引用在初始化后，不可以改变
  int c = 20;

  b = c;  // 赋值操作，而不是更改引用

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;

  return 0;
}