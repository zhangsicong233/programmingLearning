#include <iostream>

int main() {
  // 二维数组名作用
  // 1. 查看二维数组所占内存空间
  // 2. 获取二维数组首地

  // 1.
  int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  std::cout << "二维数组占用内存空间大小为：" << sizeof(arr) << std::endl;
  std::cout << "二维数组第一行占用的内存空间大小为：" << sizeof(arr[0])
            << std::endl;
  std::cout << "二维数组每一个元素占用的内存空间大小为：" << sizeof(arr[0][0])
            << std::endl;
  std::cout << "行数：" << sizeof(arr) / sizeof(arr[0]) << std::endl;
  std::cout << "列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << std::endl;

  // 2.
  std::cout << "二维数组首地址为：" << arr << std::endl;
  std::cout << "二维数组第一行首地址为：" << &arr[0] << std::endl;
  std::cout << "二维数组第二行首地址为：" << &arr[1] << std::endl;

  std::cout << "二维数组第一个元素首地址为：" << &arr[0][0] << std::endl;
  std::cout << "二维数组第二个元素首地址为：" << &arr[0][1] << std::endl;

  return 0;
}