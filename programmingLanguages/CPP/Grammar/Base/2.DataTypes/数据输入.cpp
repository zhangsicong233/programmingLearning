#include <iostream>
#include <string>

int main() {
  // 整型
  int a = 0;
  std::cout << "please input a value for int a:" << std::endl;
  std::cin >> a;

  std::cout << "a = " << a << std::endl;

  // 浮点型
  float f = 3.14f;
  std::cout << "please input a value for float f:" << std::endl;
  std::cin >> f;

  std::cout << "f = " << f << std::endl;

  // 字符型
  char ch = 'a';
  std::cout << "please input a value for char ch:" << std::endl;
  std::cin >> ch;

  std::cout << "ch = " << ch << std::endl;

  // 字符串型
  std::string str = "hello world";
  std::cout << "please input a value for string str:" << std::endl;
  std::cin >> str;

  std::cout << "str = " << str << std::endl;

  // 布尔型
  bool flag = 1;
  std::cout << "please input a value for bool flag:" << std::endl;
  std::cin >> flag;

  std::cout << "flag = " << flag << std::endl;

  return 0;
}