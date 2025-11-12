#include <iostream>

// 函数重载
// 可以让函数名相同，提高函数复用性

// 函数重载满足条件
// 1、同一个作用域下
// 2、函数名称相同
// 3、函数参数 类型/个数/顺序 不同
void func() { std::cout << "func 的调用" << std::endl; }

void func(int a) { std::cout << "func(int a) 的调用" << std::endl; }

void func(double a) { std::cout << "func(double a) 的调用" << std::endl; }

void func(int a, double b) {
  std::cout << "func(int a, double b) 的调用" << std::endl;
}

void func(double a, int b) {
  std::cout << "func(double a, int b) 的调用" << std::endl;
}

// 注意事项
// 函数返回值不可以作为函数重载的条件
int main() {
  func();
  func(10);
  func(3.14);

  func(10, 3.14);
  func(3.14, 10);

  return 0;
}