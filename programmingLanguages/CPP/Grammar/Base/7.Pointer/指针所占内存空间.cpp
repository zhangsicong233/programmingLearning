#include <iostream>

int main() {
  // 指针所占内存空间大小
  int a = 10;
  int* ptr = &a;

  // 无论何种类型的指针，在 32 位环境下总占 4 字节，在 64 位环境下总占 8 字节
  std::cout << "sizeof(int*) = " << sizeof(int*) << std::endl;
  std::cout << "sizeof(float*) = " << sizeof(float*) << std::endl;
  std::cout << "sizeof(double*) = " << sizeof(double*) << std::endl;
  std::cout << "sizeof(char*) = " << sizeof(char*) << std::endl;

  return 0;
}