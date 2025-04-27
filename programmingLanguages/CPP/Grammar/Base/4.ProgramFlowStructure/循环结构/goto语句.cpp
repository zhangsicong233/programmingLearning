#include <iostream>

int main() {
  // goto 语句
  std::cout << "1. xxxx" << std::endl;

  std::cout << "2. xxxx" << std::endl;

  goto FLAG;

  std::cout << "3. xxxx" << std::endl;

  std::cout << "4. xxxx" << std::endl;

FLAG:
  std::cout << "5. xxxx" << std::endl;

  return 0;
}