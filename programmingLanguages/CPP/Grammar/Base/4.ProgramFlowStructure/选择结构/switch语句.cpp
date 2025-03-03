#include <iostream>

int main() {
  // switch 语句

  // 电影打分
  // 9 - 10  经典
  // 7 - 8  非常好
  // 5 - 6  一般
  // <5  烂片

  // 1. 提示用户给电影评分
  int score = 0;
  std::cout << "请给电影打分" << std::endl;
  std::cin >> score;

  std::cout << "您打的分数为：" << score << std::endl;

  // 2. 根据用户输入的分数来提示用户最后的结果
  switch (score) {
    case 10:
    case 9:
      std::cout << "您认为是经典电影" << std::endl;
      break;
    case 8:
    case 7:
      std::cout << "您认为电影非常好" << std::endl;
      break;
    case 6:
    case 5:
      std::cout << "您认为电影一般" << std::endl;
      break;
    default:
      std::cout << "您认为这是烂片" << std::endl;
  }

  return 0;
}