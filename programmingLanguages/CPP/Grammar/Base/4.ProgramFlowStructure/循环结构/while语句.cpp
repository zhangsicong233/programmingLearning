#include <iostream>

int main() {
  // while 循环
  // 在屏幕中打印 0-9 这十个数字
  int num = 0;
  // 注意：写循环时一定要注意死循环
  while (num < 10) {
    std::cout << num << std::endl;

    ++num;
  }

  return 0;
}