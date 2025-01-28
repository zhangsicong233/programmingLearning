#include <iostream>

// 常量的定义方式
// 1. #define 宏常量
// 2. const 修饰的变量

// 宏常量
#define DAY 7

int main() {
  std::cout << "一周总共有 " << DAY << " 天" << std::endl;

  // const 修饰的变量
  const int month = 12;
  std::cout << "一年总共有 " << month << " 月" << std::endl;

  return 0;
}