#include <iostream>

int main() {
  // do ... while 语句
  // 在屏幕中输出 0-9 这十个数字
  int num = 0;
  do {
    std::cout << num << std::endl;

    ++num;
  } while (num < 10);

  // do ... while 和 while 区别在于 do ... while 会先执行一次循环语句。

  return 0;
}