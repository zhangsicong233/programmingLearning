#include <iostream>

int main() {
  // 可利用 sizeof 求出数据类型占用内存空间大小
  // 语法：sizeof （数据类型/变量）
  short num1 = 10;
  std::cout << "short 占用内存空间大小为：" << sizeof(short) << std::endl;
  std::cout << "short 占用内存空间大小为：" << sizeof num1 << std::endl;

  int num2 = 10;
  std::cout << "int 占用内存空间大小为：" << sizeof(int) << std::endl;
  std::cout << "int 占用内存空间大小为：" << sizeof num2 << std::endl;

  long num3 = 10;
  std::cout << "long 占用内存空间大小为：" << sizeof(long) << std::endl;
  std::cout << "long 占用内存空间大小为：" << sizeof num3 << std::endl;

  long long num4 = 10;
  std::cout << "long long 占用内存空间大小为：" << sizeof(long long)
            << std::endl;
  std::cout << "long long 占用内存空间大小为：" << sizeof num4 << std::endl;

  return 0;
}