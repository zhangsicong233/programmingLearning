#include <iostream>

// 值传递
// 值传递时，形参改变不影响实参

void swap(int x, int y) {
  std::cout << "交换前：";
  std::cout << "x = " << x << " ";
  std::cout << "y = " << y << std::endl;

  int temp = x;
  x = y;
  y = temp;

  std::cout << "交换后：";
  std::cout << "x = " << x << " ";
  std::cout << "y = " << y << std::endl;
}

int main() {
  int a = 10;
  int b = 20;

  std::cout << "a = " << a << " ";
  std::cout << "b = " << b << std::endl;

  swap(a, b);

  std::cout << "a = " << a << " ";
  std::cout << "b = " << b << std::endl;

  return 0;
}