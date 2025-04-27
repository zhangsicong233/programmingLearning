#include <iostream>

int main() {
  // continue 语句
  for (int i = 0; i <= 100; ++i) {
    if (i % 2 == 0) {
      continue;
    }
    std::cout << i << std::endl;
  }

  return 0;
}