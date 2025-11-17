#include <iostream>

// 普通函数与函数模板的区别
// 1、普通函数调用可以发生隐式类型转换
// 2、函数模板 用自动类型推导，不可以发生隐式类型转换
// 3、函数模板 用显式指定类型，可以发生隐式类型转换

int myAdd01(int x, int y) { return x + y; }

template <class T> T myAdd(T x, T y) { return x + y; }

void test01() {
  int a = 10;
  int b = 20;
  char c = 'c'; // 'a' = 97

  std::cout << myAdd01(a, c) << std::endl;

  // 自动类型推导  不会发生隐式类型转换
  // std::cout << myAdd(a, c) << std::endl;

  // 显示指定类型  会发生隐式类型转换
  std::cout << myAdd<int>(a, c) << std::endl;
}

int main() {
  test01();

  return 0;
}