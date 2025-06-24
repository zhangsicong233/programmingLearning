#include <iostream>
#include <vector>

int main() {
  // 数组名用途
  // 1. 统计整个数组在内存中的长度
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "整个数组占用内存空间大小：" << sizeof(arr) << std::endl;
  std::cout << "每个元素占用内存空间大小" << sizeof(arr[0]) << std::endl;
  std::cout << "数组中元素个数为" << sizeof(arr) / sizeof(arr[0]) << std::endl;

  // 2. 获取数组在内存中的首地址
  std::cout << "数组首地址为：" << arr << std::endl;
  std::cout << "数组第一个元素地址为：" << &arr[0] << std::endl;
  std::cout << "数组第二个元素地址为：" << &arr[1] << std::endl;

  // 注意
  // 数组名是一个常量，不可以进行赋

  return 0;
}