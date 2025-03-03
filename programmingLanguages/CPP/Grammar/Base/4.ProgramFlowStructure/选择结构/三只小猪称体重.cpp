#include <iostream>

int main() {
  double pg = -1;
  double pg2 = -1;
  double pg3 = -1;
  std::cout << "请输入三只小猪的体重" << std::endl;
  std::cin >> pg >> pg2 >> pg3;

  if (pg < 0 || pg2 < 0 || pg3 < 0) {
    std::cout << "输入的数据有误" << std::endl;
  } else {
    if (pg > pg2 && pg > pg3) {
      std::cout << "小猪 1 最重" << std::endl;
    } else if (pg2 > pg && pg2 > pg3) {
      std::cout << "小猪 2 最重" << std::endl;
    } else {
      std::cout << "小猪 3 最重" << std::endl;
    }
  }

  return 0;
}