#include <iostream>

int main() {
  // 整型
  // 1.短整型 (-2^15 ~ 2^15 - 1 / -32768 ~ 32767)
  short num1 = 32768;

  // 2. 整型 (-2^31 ~ 2^31 - 1 / -2147483648 ~ 2147483647)
  int num2 = 32768;

  // 3. 长整型 (-2^31 ~ 2^31 - 1 / -2147483648 ~ 2147483647)
  long num3 = 10;

  // 4. 长长整型 (-2^63 ~ 2^63 - 1 / -9223372036854 ~ 9223372036854775807)
  long long num4 = 10;

  std::cout << "num1 = " << num1 << std::endl;
  std::cout << "num2 = " << num2 << std::endl;
  std::cout << "num3 = " << num3 << std::endl;
  std::cout << "num4 = " << num4 << std::endl;

  return 0;
}