#include <iostream>

// 加号运算符重载

class Person {
 public:
  Person() {}

  Person(int a, int b) : m_A(a), m_B(b) {}

  // 1、成员函数重载加号
  /*
  Person operator+(Person& p) {
    Person temp;
    temp.m_A = this->m_A + p.m_A;
    temp.m_B = this->m_B + p.m_B;

    return temp;
  }
  */

  Person operator+(int num) {
    Person temp;
    temp.m_A = this->m_A + num;
    temp.m_B = this->m_B + num;

    return temp;
  }

  int m_A;
  int m_B;
};

// 2、全局函数重载加号
Person operator+(Person& p1, Person& p2) {
  Person temp;
  temp.m_A = p1.m_A + p2.m_A;
  temp.m_B = p1.m_B + p2.m_B;

  return temp;
}

void test01() {
  Person p1(10, 10);
  Person p2(20, 20);

  // 成员函数重载本质 Person p3 = p1.operator+(p2);
  // 全局函数重载本质 Person p3 = operator+(p1, p2);
  Person p3 = p1 + p2;
  std::cout << "p3.m_A = " << p3.m_A << std::endl;
  std::cout << "p3.m_B = " << p3.m_B << std::endl;

  // 运算符重载也可以发生函数重载
  // Person + int
  Person p4 = p1 + 100;
  std::cout << "p4.m_A = " << p4.m_A << std::endl;
  std::cout << "p4.m_B = " << p4.m_B << std::endl;
}

int main() {
  test01();

  return 0;
}