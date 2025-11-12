#include <iostream>

// 引用本质 —— 指针常量
// 发现是引用，转换为 int* cosnt ref = &a;
void func(int& ref) {
  // ref 是引用，转换为 *ref = 100;
  ref = 100;
}

int main() {
  int a = 10;

  // 自动转换为 int* const ref = &a;
  // 指针常量是指针指向不能变，也说明为什么引用不可更改
  int& ref = a;
  // 发现 ref 是引用，自动转换为 *ref = 20;
  ref = 20;

  std::cout << "a = " << a << std::endl;
  std::cout << "ref = " << ref << std::endl;

  func(a);

  return 0;
}