#include <iostream>

int main() {
  // 三目运算符

  int a = 10;
  int b = 20;

  // 将 a 和 b 作比较，将大的值赋给 c
  int c = (a > b ? a : b);
  std::cout << "c = " << c << std::endl;

  // C++ 中三目运算符返回的是变量，可以继续赋值
  (a < b ? a : b) = 100;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  return 0;
}