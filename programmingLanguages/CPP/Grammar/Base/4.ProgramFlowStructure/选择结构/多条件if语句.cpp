#include <iostream>

int main() {
  // 选择结构  多条件 if 语句

  // 1. 输入考试分数
  int score = 0;
  std::cout << "请输入一个分数：" << std::endl;
  std::cin >> score;

  // 2.判断
  // > 600 一本
  // > 500 二本
  // > 400 三本
  // <= 400 未考上本科
  if (score > 600) {
    std::cout << "恭喜您考上一本大学" << std::endl;
  } else if (score > 500) {
    std::cout << "恭喜您考上二本大学" << std::endl;
  } else if (score > 400) {
    std::cout << "恭喜您考上三本大学" << std::endl;
  } else {
    std::cout << "很遗憾，您未考上本科" << std::endl;
  }

  return 0;
}