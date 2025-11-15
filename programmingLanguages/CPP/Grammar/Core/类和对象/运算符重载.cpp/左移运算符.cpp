#include <iostream>

// 左移运算符重载
class Person {
  friend std::ostream& operator<<(std::ostream& cout, Person& p);

 public:
  Person() {}

  Person(int a, int b) : m_A(a), m_B(b) {}

  // 利用成员函数重载
  // p.operator<<(std::cout);  简化：p << std::cout
  // 不会利用成员函数重载左移运算符，因为无法实现 std::cout 在左侧
  // std::ostream& operator<<(std::ostream& cout) { return cout; }

 private:
  int m_A;
  int m_B;
};

// 只能利用全局函数重载左移运算符
std::ostream& operator<<(std::ostream& myOut, Person& p) {
  myOut << "p.m_A = " << p.m_A << std::endl;
  myOut << "p.m_B = " << p.m_B << std::endl;

  return myOut;
}

void test01() {
  Person p(10, 10);

  std::cout << p << std::endl;
}

int main() {
  test01();

  return 0;
}