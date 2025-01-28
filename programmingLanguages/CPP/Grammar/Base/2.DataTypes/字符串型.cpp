#include <iostream>
#include <string>

int main() {
  // c 风格字符串
  // 注：1.char 字符串名 []
  //     2.等号后要用双引号包含
  char str[] = "hello world";
  std::cout << str << std::endl;

  // c++ 风格字符串
  // 注：#include <string>
  std::string str2 = "hello world";
  std::cout << str2 << std::endl;

  return 0;
}