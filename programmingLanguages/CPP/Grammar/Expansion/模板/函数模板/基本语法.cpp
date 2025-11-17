#include <iostream>

// 函数模板

// 实现两个整型交换的函数
void swapInt(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

// 实现两个浮点型交换的函数
void swapDouble(double &x, double &y) {
  double temp = x;
  x = y;
  y = temp;
}

// 函数模板
// 声明一个模板， 告诉编译器后面代码总紧跟的 T 不要报错，T 是一个通用数据类型
template <typename T> void mySwap(T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}

void test01() {
  int a = 10;
  int b = 20;

  // swapInt(a, b);
  // 利用函数模板交换
  // 两种方式使用函数模板
  // 1、自动类型推导
  mySwap(a, b);

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  std::cout << "---------------" << std::endl;

  double c = 1.1;
  double d = 2.2;

  // swapDouble(c, d);
  // 2、显式指定类型
  mySwap<double>(c, d);

  std::cout << "a = " << c << std::endl;
  std::cout << "b = " << d << std::endl;
}

int main() {
  test01();

  return 0;
}