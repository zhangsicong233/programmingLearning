// 在源文件中写函数的定义
#include "swap.h"

// 函数的定义
void swap(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
}