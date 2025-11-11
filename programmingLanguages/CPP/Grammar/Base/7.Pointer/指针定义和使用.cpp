#include <iostream>

int main() {
  // 1、定义一个指针
  int a = 10;
  // 指针定义语法：数据类型* 指针变量;
  int* ptr;
  // 让指针记录变量 a 的地址
  ptr = &a;

  std::cout << "a 的地址为：" << &a << std::endl;
  std::cout << "ptr = " << ptr << std::endl;

  // 2、使用指针
  // 通过解引用的方式找到指针指向的内存
  // 解引用：指针前加 *
  *ptr = 1000;

  std::cout << "a = " << a << std::endl;
  std::cout << "*ptr = " << *ptr << std::endl;

  return 0;
}