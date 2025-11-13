#include <iostream>

// 静态成员变量
class Person {
 public:
  // 1、所有对象共享同一份数据
  // 2、编译阶段分配内存
  // 3、类内声明，类外初始化
  static int m_A;

  // 静态成员变量也是有发访问权限的
 private:
  static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01() {
  Person p;
  std::cout << p.m_A << std::endl;

  Person p2;
  p2.m_A = 200;

  std::cout << p.m_A << std::endl;
}

void test02() {
  // 静态成员变量不属于某个对象上，所有对象共享同一份数据
  // 因此静态成员变量有两种访问方式

  // 1、通过对象进行访问
  /*
  Person p;
  std::cout << p.m_A << std::endl;
  */

  // 2、通过类名进行访问
  std::cout << Person::m_A << std::endl;
  // std::cout << Person::m_B << std::endl;  // 私有权限，类外无法访问
}

int main() {
  // test01();
  test02();

  return 0;
}