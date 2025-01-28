#include <iostream>

int main() {
  // bool 类型
  // true 真    false 假
  // 本质： 1 代表真    0 代表假
  bool flag = true;
  std::cout << flag << std::endl;

  flag = false;
  std::cout << flag << std::endl;

  // bool 所占内存空间
  std::cout << "size of bool = " << sizeof(bool) << std::endl;

  return 0;
}