#include <iostream>

int main() {
  // 空指针
  // 1、空指针用于给指针变量初始化
  int* ptr = nullptr;

  // 2、空指针不可以进行访问
  // 0 ~ 255 之间的内存编号是系统占用的，因此不可以访问
  // *ptr = 100;  错误，无权限进行访问

  return 0;
}