#include <iostream>

int main() {
  int a = 10;
  int b = 20;

  // 1、const 修饰指针  常量指针
  const int* ptr1 = &a;
  // 指针指向的值不可更改
  // 指针指向的地址可以更改
  // *ptr1 = 20; 错误
  ptr1 = &b;

  // 2、const 修饰常量  指针常量
  int* const ptr2 = &a;
  // 指针指向的地址不可更改
  // 指针指向的值可以更改
  // ptr2 = &b;  错误
  *ptr2 = 100;

  // 3、const 既修饰指针又修饰常量
  const int* const ptr3 = &a;
  // 指针指向的值不可更改
  // 指针指向的地址不可更改
  // *ptr3 = 1000;  错误
  // ptr3 = &b;  错误

  return 0;
}