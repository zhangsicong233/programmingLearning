#include <iostream>

int main() {
  // 取模运算的本质就是求余数
  int a1 = 10;
  int b1 = 3;
  std::cout << a1 % b1 << std::endl;

  int a2 = 10;
  int b2 = 20;
  std::cout << a2 % b2 << std::endl;

  int a3 = 10;
  int b3 = 0;
  // std::cout << a3 % b3 << std::endl; // 两数相除除数不能为
  // 0，所以也做不了取模运算

  // 两个小数不可以做取模运算
  double d1 = 3.14;
  double d2 = 11.45;
  // std::cout << d1 % d2 << std::endl;

  return 0;
}