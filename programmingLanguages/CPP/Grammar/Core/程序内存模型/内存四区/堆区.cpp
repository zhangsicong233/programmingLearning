#include <iostream>

// 在堆区开辟数据
int* function() {
  // 利用 new 关键字  可以将数据开辟到堆区
  // 指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
  int* ptr = new int(10);

  return ptr;
}

int main() {
  int* ptr = function();
  std::cout << *ptr << std::endl;

  return 0;
}