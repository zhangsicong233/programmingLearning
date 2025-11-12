#include <iostream>

// 引用做函数参数
// 交换函数

// 1、值传递
void swap01(int x, int y) {
  int temp = x;
  x = y;
  y = temp;

  std::cout << "swap01中：" << std::endl;
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
}

// 2、地址传递
void swap02(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;

  std::cout << "swap02中：" << std::endl;
  std::cout << "x = " << *x << std::endl;
  std::cout << "y = " << *y << std::endl;
}

// 3、引用传递
void swap03(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;

  std::cout << "swap03中：" << std::endl;
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
}

int main() {
  int a = 10;
  int b = 20;

  // 值传递，形参不会修饰实参
  // swap01(a, b);

  // 地址传递，形参会修饰实参
  // swap02(&a, &b);

  // 引用传递，形参会修饰实参
  swap03(a, b);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  return 0;
}