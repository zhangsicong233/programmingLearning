#include <iostream>

// 函数的常见样式
// 1、 无参无返
void test01() { std::cout << "this is test01" << std::endl; }

// 2、 有参无返
void test02(int x) { std::cout << "this is test02, x = " << x << std::endl; }

// 3、 无参有返
int test03() {
  std::cout << "this is test03" << std::endl;

  return 100;
}

// 4、 有参有返
int test04(int x) {
  std::cout << "this is test04, x = " << x << std::endl;

  return x;
}

int main() {
  // 无参无返函数调用
  test01();

  // 有参无返函数调用
  test02(100);

  // 无参有返函数调用
  int num1 = test03();
  std::cout << "num1 = " << num1 << std::endl;

  // 有参有返函数调用
  int num2 = test04(10000);
  std::cout << "num2 = " << num2 << std::endl;

  return 0;
}