#include <iostream>

int main() {
  // 选择结构  多行 if 语句

  // 1. 输入考试分数
  int score = 0;
  std::cout << "请输入一个分数：" << std::endl;
  std::cin >> score;

  // 2. 如果大于 600，打印考上一本，否则打印未考上一本
  if (score > 600) {
    std::cout << "恭喜您考上一本大学" << std::endl;
  } else {
    std::cout << "很遗憾，您未考上一本大学" << std::endl;
  }

  return 0;
}