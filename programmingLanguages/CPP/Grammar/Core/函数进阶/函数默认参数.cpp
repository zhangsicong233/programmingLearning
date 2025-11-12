#include <iostream>

// 函数默认参数
// 如果我们自己传入了数据就用自己的数据，如果没有就用默认值
// 语法： 返回值类型 函数名（形参 = 默认值）
int func(int a, int b = 20, int c = 30) { return a + b + c; }

// 注意事项
// 1、如果某个参数已经有了默认值，那么从这个位置往后，都必须有默认值
// int func02(int a, int b = 10, int c) { return a + b + c; }   // 错误

// 2、如果函数的声明有默认参数，函数的实现不能有默认参数
// 声明和实现只能有一个有默认参数
int func02(int a = 10, int b = 10);

// int func02(int a = 10, int b = 10) { return a + b; }   // 错误

int main() {
  std::cout << func(10, 30) << std::endl;

  return 0;
}