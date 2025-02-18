#include <iostream>

int main() {
  // 逻辑运算符
  // 非 ！ 真变假，假变真
  int a = 10;  // C++ 中 除了 0 都为真
  std::cout << !a << std::endl;

  // 与 &&  同真为真，其余为假
  int a2 = 10;
  int b2 = 10;
  std::cout << (a2 && b2) << std::endl;

  a2 = 0;
  b2 = 10;
  std::cout << (a2 && b2) << std::endl;

  a2 = 0;
  b2 = 0;
  std::cout << (a2 && b2) << std::endl;

  // 或 ||  全假为假，其余为真
  int a3 = 10;
  int b3 = 10;
  std::cout << (a3 || b3) << std::endl;

  a3 = 0;
  b3 = 10;
  std::cout << (a3 || b3) << std::endl;

  a3 = 0;
  b3 = 0;
  std::cout << (a3 || b3) << std::endl;

  return 0;
}