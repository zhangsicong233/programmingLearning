#include <iostream>

// 实现两个数字交换
void swap01(int x, int y) {
  int temp = x;
  x = y;
  y = temp;

  std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
}

void swap02(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;

  std::cout << "*x = " << *x << "\t" << "*y = " << *y << std::endl;
}

int main() {
  // 指针和函数
  int a = 10;
  int b = 20;

  // 值传递（形参无法改变实参）
  swap01(a, b);
  std::cout << "a = " << a << "\t" << "b = " << b << std::endl;

  // 地址传递（形参可以改变实参）
  swap02(&a, &b);
  std::cout << "a = " << a << "\t" << "b = " << b << std::endl;

  return 0;
}