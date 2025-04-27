#include <iostream>

int main() {
  // break 使用时机
  // 1. switch 语句中
  std::cout << "请选择副本难度：" << std::endl;
  std::cout << "1. 普通" << std::endl;
  std::cout << "2. 中等" << std::endl;
  std::cout << "3. 困难" << std::endl;

  int select = 0;
  std::cin >> select;
  switch (select) {
    case 1:
      std::cout << "选择的是普通难度" << std::endl;
      break;
    case 2:
      std::cout << "选择的是中等难度" << std::endl;
      break;
    case 3:
      std::cout << "选择的是困难难度" << std::endl;
      break;

    default:
      break;
  }

  // 2. 循环语句中
  for (int i = 0; i < 10; ++i) {
    if (i == 5) {
      break;
    }
    std::cout << i << std::endl;
  }

  // 3. 嵌套循环语句中
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j == 5) {
        break;
      }
      std::cout << " * ";
    }
    std::cout << "\n";
  }

  return 0;
}