#include <iostream>

int main() {
  for (int num = 1; num <= 100; ++num) {
    if (num % 10 == 7 || num / 10 == 7 || num % 7 == 0) {
      std::cout << "敲桌子" << std::endl;
    } else {
      std::cout << num << std::endl;
    }
  }

  return 0;
}