#include <iostream>

int main() {
  // 指针和数组
  // 利用指针访问数组中的元素

  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int* ptr = arr;  // arr 就是数组的首地址
  std::cout << "利用指针访问数组第一个元素：" << *ptr << std::endl;

  ++ptr;  // 让指针向后偏移 8 个字节
  std::cout << "利用指针访问第二个元素：" << *ptr << std::endl;

  std::cout << "利用指针遍历数组" << std::endl;

  int* ptr2 = arr;
  for (int i = 0; i < 10; ++i) {
    std::cout << *(ptr2 + i) << " ";
  }
  std::cout << std::endl;

  return 0;
}