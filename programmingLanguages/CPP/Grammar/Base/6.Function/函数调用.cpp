#include <iostream>

// 函数定义的时候，x，y没有真实数据，称为形参
int add(int x, int y) {
  int ans = x + y;

  return ans;
}

int main() {
  // main函数中调用add函数
  int a = 10;
  int b = 20;

  // 函数调用语法：
  // 函数名称（参数）
  // a, b称为实参
  int ans = add(a, b);
  std::cout << ans << std::endl;

  return 0;
}