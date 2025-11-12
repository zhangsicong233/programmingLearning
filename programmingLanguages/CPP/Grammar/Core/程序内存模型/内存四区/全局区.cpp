#include <cstdint>
#include <iostream>

// 全局变量
int g_A = 20;
int g_B = 20;

// const 修饰的全局变量  全局常量
const int c_G_A = 40;
const int c_G_B = 40;

int main() {
  // 全局区
  // 全局变量、静态变量、常量

  // 创建普通局部变量
  int l_A = 10;
  int l_B = 20;
  // 打印局部变量的地址
  std::cout << "局部变量 l_A 的地址: " << reinterpret_cast<std::uintptr_t>(&l_A)
            << std::endl;
  std::cout << "局部变量 l_B 的地址: " << reinterpret_cast<std::uintptr_t>(&l_B)
            << std::endl;

  // 打印全局变量的地址
  std::cout << "全局变量 g_A 的地址：" << reinterpret_cast<uintptr_t>(&g_A)
            << std::endl;
  std::cout << "全局变量 g_B 的地址：" << reinterpret_cast<uintptr_t>(&g_B)
            << std::endl;

  // 静态变量  在普通变量前加 static
  static int s_A = 30;
  static int s_B = 30;
  // 打印静态变量的地址
  std::cout << "静态变量 s_A 的地址：" << reinterpret_cast<uintptr_t>(&s_A)
            << std::endl;
  std::cout << "静态变量 s_B 的地址：" << reinterpret_cast<uintptr_t>(&s_B)
            << std::endl;

  // 常量
  // 字符串常量
  std::cout << "字符串常量 'Hello world' 的地址："
            << reinterpret_cast<uintptr_t>("Hello World") << std::endl;

  // const 修饰的变量
  // 打印 const 修饰的全局变量的地址

  std::cout << "全局常量 c_G_A 的地址：" << reinterpret_cast<uintptr_t>(&c_G_A)
            << std::endl;
  std::cout << "全局常量 c_G_B 的地址：" << reinterpret_cast<uintptr_t>(&c_G_B)
            << std::endl;

  // const 修饰的局部变量
  const int c_L_A = 50;
  const int c_L_B = 50;
  // 打印 const 修饰的局部变量的地址
  std::cout << "局部常量 c_L_A 的地址：" << reinterpret_cast<uintptr_t>(&c_L_A)
            << std::endl;
  std::cout << "局部常量 c_L_B 的地址：" << reinterpret_cast<uintptr_t>(&c_L_B)
            << std::endl;

  // 总结：
  // 不在全局区 ： 局部变量、const 修饰的局部变量（局部常量）
  // 在全局区： 全局变量、静态变量（static 关键字）、字符串常量、全局常量（const
  // 修饰的全局变量)

  return 0;
}