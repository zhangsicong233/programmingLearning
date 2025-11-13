#include <iostream>

// 成员变量和成员函数分开存储

class Person {
 public:
  // 非静态成员函数  不属于类的对象上
  void func() {}

  // 静态成员函数  不属于类的对象上
  static void func02() {}

  // 非静态成员变量  属于类的对象上
  int m_A;

  // 静态成员变量  不属于类的对象上
  static int m_B;
};

int Person::m_B = 10;

void test01() {
  Person p;

  // 空对象占用的内存空间为：1
  // C++
  // 编译器会给每个空对象分配一个字节空间，是为了区分每个空对象所占内存的位置
  // 每个空对象都该有一个独一无二的内存地址
  std::cout << "size of p = " << sizeof(p) << std::endl;
}

void test02() {
  Person p;
  std::cout << "size of p = " << sizeof(p) << std::endl;
}

int main() {
  // test01();
  test02();

  return 0;
}