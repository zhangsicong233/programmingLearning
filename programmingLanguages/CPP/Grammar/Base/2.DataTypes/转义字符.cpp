#include <iostream>

int main() {
  // 转义字符
  // 换行符 '\n'
  std::cout << "hello world\n";

  // 反斜杠 '\\'
  std::cout << "\\" << std::endl;

  // 水平制表符 '\t'  可以整齐输出数据
  std::cout << "aaaa\t" << "hello world" << std::endl;
  std::cout << "aa\t" << "hello world" << std::endl;
  std::cout << "aaaaaa\t" << "hello world" << std::endl;

  return 0;
}