#include <iostream>

// 常量引用
// 使用场景：用来修饰形参，防止误操作
// 打印数据函数
void showValue(const int& num) {
  // 使用 const 防止误操作改变 num 的值
  // num = 1000;

  std::cout << "num = " << num << std::endl;
}

int main() {
  int a = 10;

  // 引用必须引一块合法的内存空间
  // int& ref = 10;  // 错误
  // 加上 const 之后，编译器将代码修改
  /*
  int temp = 10；
  const int& ref = temp;
  */
  const int& ref = 10;
  // 加入 const 之后变为只读，不可以修改
  // ref = 20;

  int num = 100;
  showValue(num);

  return 0;
}