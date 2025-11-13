#include <iostream>

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person {
 public:
  // 静态成员函数
  static void func() {
    std::cout << "static void func() 调用" << std::endl;

    // 静态成员函数可以访问 静态成员变量
    m_A = 100;
    // m_B = 200; // 静态成员函数 不可访问 非静态成员变量
  }

  static int m_A;  // 静态成员变量
  int m_B;         // 非静态成员变量

  // 静态成员函数也是有访问权限的
 private:
  static void func02() {
    std::cout << "static void func02() 调用" << std::endl;
  }
};

int Person::m_A = 0;

// 有两种访问方式
void test01() {
  // 1、通过对象调用
  Person p;
  p.func();

  // 2、通过类名调用
  Person::func();
  // Person::func02();  // 私有权限，类外无法访问
}

int main() {
  test01();

  return 0;
}