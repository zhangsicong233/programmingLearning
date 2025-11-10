#include <iostream>

// 函数的声明

// 提前告诉编译器函数的存在，可以利用函数的声明
// max 函数的声明
// 声明可以写多次，但是定义只能有一次
int max(int x, int y);

int main() {
  int a = 0;
  int b = 1;
  std::cout << max(a, b) << std::endl;

  return 0;
}

// max 函数， 实现两个整型数字进行比较，返回较大值
int max(int x, int y) { return x > y ? x : y; }