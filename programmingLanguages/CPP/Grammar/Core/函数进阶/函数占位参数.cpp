#include <iostream>

// 函数占位参数
// 语法：返回值类型 函数名（数据类型）（）

// 目前阶段占位参数还用不到，后面课程中会用到
// 占位参数可以有默认参数
void func(int a, int) { std::cout << "this is func" << std::endl; }

int main() {
  func(10, 100);

  return 0;
}