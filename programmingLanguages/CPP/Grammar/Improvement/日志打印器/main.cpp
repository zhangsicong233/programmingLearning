#include "Logger.hpp"

int main() {
  int a = 10;
  Logger<int>::log(a);

  int* ptr = &a;
  Logger<int*>::log(ptr);

  std::string str = "hello world";
  Logger<std::string>::log(str);

  std::cout << "Logging multiple parameters: " << std::endl;
  double* pNull = nullptr;
  logAll(a, ptr, str, pNull);

  return 0;
}