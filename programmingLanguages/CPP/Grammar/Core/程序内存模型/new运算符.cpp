#include <iostream>

// new 的基本语法
int* func() {
  // 在堆区创建整型数据
  // new 返回的是 该数据类型的指针
  int* ptr = new int(10);

  return ptr;
}

// 在堆区利用 new 开辟数组
void test() {
  // 创建 10 整型数据的数组，在堆区
  int* arrPtr = new int[10];  // 10 代表数组有 10 个元素
  for (int i = 0; i < 10; ++i) {
    arrPtr[i] = i;  // 给 10 个元素赋值
  }

  for (int i = 0; i < 10; ++i) {
    std::cout << arrPtr[i] << std::endl;
  }

  // 释放堆区数组
  // 释放数组时要加 []
  delete[] arrPtr;
}

int main() {
  int* ptr = func();
  std::cout << *ptr << std::endl;
  // 堆区的数据  由程序员管理开辟，程序员管理释放
  // 如果想释放堆区的数据，利用关键字 delete
  delete ptr;
  // std::cout << *ptr << std::endl;  //内存已释放，不可访问

  test();

  return 0;
}