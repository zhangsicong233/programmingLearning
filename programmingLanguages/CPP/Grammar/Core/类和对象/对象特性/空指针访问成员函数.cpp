#include <iostream>

// 空指针访问成员函数

class Person {
 public:
  void showClassName() { std::cout << "this is Person class" << std::endl; }

  // 报错原因是  传入的指针为 nullptr
  void showPersonAge() {
    if (this == nullptr) {
      return;
    }

    std::cout << "age = " << m_Age << std::endl;
  }

  int m_Age;
};

void test01() {
  Person* p = nullptr;

  // p->showClassName();
  p->showPersonAge();
}

int main() {
  test01();

  return 0;
}