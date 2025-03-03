#include <iostream>

int main() {
  // 1. 输入高考分数
  int score = 0;
  std::cout << "请输入一个高考考试分数" << std::endl;
  std::cin >> score;

  std::cout << "您输入的分数为：" << score << std::endl;

  // 2. 判断
  // >600 一本
  // >700 北大
  // >650 清华
  // 其余 人大
  // >500 二本
  // >400 三本
  // 其余情况  未考上
  if (score > 600) {
    std::cout << "恭喜您考上了一本大学" << std::endl;
    if (score > 700) {
      std::cout << "您考上的是北大" << std::endl;
    } else if (score > 650) {
      std::cout << "您考上的是清华" << std::endl;
    } else {
      std::cout << "您考上的是人大" << std::endl;
    }
  } else if (score > 500) {
    std::cout << "恭喜您考上了二本大学" << std::endl;
  } else if (score > 400) {
    std::cout << "恭喜您考上了三本大学" << std::endl;
  } else {
    std::cout << "很遗憾，您未考上本科" << std::endl;
  }

  return 0;
}