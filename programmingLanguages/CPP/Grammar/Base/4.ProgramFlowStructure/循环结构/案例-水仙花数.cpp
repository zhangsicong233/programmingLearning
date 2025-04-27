#include <math.h>

#include <iostream>

int main() {
  int num = 100;
  int tmp = 0;
  do {
    tmp = std::pow(num % 10, 3) + std::pow(num / 100, 3) +
          std::pow(num / 10 % 10, 3);
    if (tmp == num) {
      std::cout << num << std::endl;
    }

    ++num;
  } while (num < 999);

  return 0;
}