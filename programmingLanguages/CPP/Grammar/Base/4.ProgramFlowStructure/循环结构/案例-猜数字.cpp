#include <iostream>

int main() {
  int num = rand() % 100 + 1;
  int ans = 0;
  std::cout << "请输入你所猜测的数字：" << std::endl;
  std::cin >> ans;

  while (ans != num) {
    if (ans < num) {
      std::cout << "猜小了。" << std::endl;
    } else {
      std::cout << "猜大了。" << std::endl;
    }

    std::cout << "请重新输入：" << std::endl;
    std::cin >> ans;
  }

  std::cout << "恭喜你，猜对了。" << std::endl;

  return 0;
}