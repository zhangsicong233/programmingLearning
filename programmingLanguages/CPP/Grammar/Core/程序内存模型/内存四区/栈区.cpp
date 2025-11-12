#include <iostream>

// 栈区数据的注意事项  --- 不要返回局部变量的地址
// 栈区的数据由编译器管理开辟和释放

// 形参数据也会放在栈区
int* function(int x) {
  // 局部变量  存放在栈区，栈区的数据在函数执行完后自动释放
  int a = 10;
  x = 100;

  return &a;
}

int main() {
  // 接收 func() 的返回值
  // int* ptr = function(1);
  // std::cout << *ptr << std::endl;
  // 以上均为非法操作

  return 0;
}