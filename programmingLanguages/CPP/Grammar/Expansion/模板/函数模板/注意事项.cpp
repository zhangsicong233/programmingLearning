#include <iostream>

// 函数模板注意事项
// 1、自动类型推导，必须推导出一致的类型 T 才能使用
// 2、模板必须要确定出 T 的数据类型，才可以使用

// typename 可以替换为 class
template <typename T>
void mySwap(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

template <class T>
void func() {
  std::cout << "func() 调用" << std::endl;
}

void test01() {
  int a = 10;
  int b = 20;
  char c = 'c';

  // mySwap(a, b); // 正确
  // mySwap(a, c); // 错误，推导不出一致的 T 类型

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
}

void test02() { func<int>(); }

int main() {
  // test01();
  test02();

  return 0;
}