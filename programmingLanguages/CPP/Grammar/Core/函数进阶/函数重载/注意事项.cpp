#include <iostream>

// 函数重载注意事项
// 1、引用作为重载条件
void func(int& a) { std::cout << "func(int& a) 调用" << std::endl; }

void func(const int& a) { std::cout << "func(const int& a) 调用" << std::endl; }

// 2、函数重载碰到函数默认参数
void func02(int a) { std::cout << "func02(int a) 调用" << std::endl; }

void func02(int a, int b = 10) {
  std::cout << "func02(int a, int b = 10) 调用" << std::endl;
}

int main() {
  int a = 10;
  func(a);
  func(10);

  // 当函数重载碰到默认参数会出现二义性，报错，尽量避免
  // func02(10);

  return 0;
}