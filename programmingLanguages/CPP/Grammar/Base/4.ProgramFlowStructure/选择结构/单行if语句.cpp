#include <iostream>

int main() {
  // 选择结构  单行 if 语句

  // 1、用户输入分数
  int score = 0;
  std::cout << "请输入一个分数：" << std::endl;
  std::cin >> score;

  // 2、打印用户输入的分数
  std::cout << "您输入的分数为：" << score << std::endl;

  // 3、判断分数是否大于 600，如果大于，那么输出 恭喜您考上了
  // 注意事项  if 条件后面不要加分号
  if (score > 600) {
    std::cout << "恭喜您考上了一本大学" << std::endl;
  }

  return 0;
}
