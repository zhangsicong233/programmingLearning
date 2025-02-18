#include <iostream>

int main() {
  // 赋值运算符
  int a = 10;

  // =
  a = 100;
  std::cout << "a = " << a << std::endl;

  // +=
  a = 10;
  a += 2;  // a = a + 2
  std::cout << "a = " << a << std::endl;

  // -=
  a = 10;
  a -= 2;  // a = a - 2
  std::cout << "a = " << a << std::endl;

  // *=
  a = 10;
  a *= 2;  // a = a*2
  std::cout << "a = " << a << std::endl;

  // /=
  a = 10;
  a /= 2;  // a = a/2
  std::cout << "a = " << a << std::endl;

  // %=
  a = 10;
  a %= 2;  // a = a%2
  std::cout << "a = " << a << std::endl;

  return 0;
}