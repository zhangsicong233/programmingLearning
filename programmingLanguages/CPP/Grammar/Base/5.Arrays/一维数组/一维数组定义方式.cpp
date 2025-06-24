#include <iostream>

int main() {
  // 数组

  /*
  1.数据类型  数组名[数组长度]
  2.数据类型  数组名[数组长度] = {值1 、2、3}
  3.数据类型  数组名[] = {值1、2、3}
  */

  // 1.
  int arr[5];
  // 给数组中的元素赋值
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  // 访问数组元素
  std::cout << arr[0] << std::endl;

  // 2.
  // 如果在初始化数据的时候，没有全部填写完，会用0来填充
  int arr2[5] = {10, 20, 30, 40, 50};
  std::cout << arr2[0] << std::endl;

  // 利用循环的方式输出数组中元素
  for (int i = 0; i < 5; ++i) {
    std::cout << arr2[i] << std::endl;
  }

  // 3.
  // 定义数组的时候，必须有初始长度
  int arr3[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
  for (int i = 0; i < 9; ++i) {
    std::cout << arr3[i] << std::endl;
  }

  return 0;
}