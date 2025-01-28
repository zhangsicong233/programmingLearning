#include <iostream>

int main() {
  char ch = 'a';
  std::cout << ch << std::endl;
  std::cout << "char 所占内存 " << sizeof(char) << std::endl;

  // 常见错误
  // char ch2 = "b"    // 错误，只能用单引号
  // char ch3 = 'abcba'    // 错误，只能是单个字符

  // char 对应 ASCII 编码
  // 常见 a = 97, A = 65
  std::cout << (int)ch << std::endl;

  return 0;
}