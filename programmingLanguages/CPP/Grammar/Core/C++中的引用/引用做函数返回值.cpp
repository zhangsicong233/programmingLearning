#include <iostream>

// 引用做函数返回值
// 1、不要返回局部变量的引用
/*
int& test01() {
  // 局部变量，存放在栈区
  int a = 10;

  return a;
}
*/

// 2、函数的调用可以作为左值
int& test02() {
  // 静态变量，存放在全局区
  // 全局区上的数据在程序结束后由系统释放
  static int a = 10;

  return a;
}

int main() {
  // int& ref = test01();
  // std::cout << ref << std::endl;
  // 以上均为非法操作

  int& ref = test02();
  std::cout << "ref = " << ref << std::endl;

  // 如果函数的返回值是引用，这个函数可以作为左值
  test02() = 1000;

  std::cout << "ref = " << ref << std::endl;

  return 0;
}