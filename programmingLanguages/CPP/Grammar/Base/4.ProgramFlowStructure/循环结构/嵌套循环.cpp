#include <iostream>

int main() {
  // 利用嵌套循环打印星图
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << "*" << " ";
    }

    std::cout << "\n";
  }

  return 0;
}