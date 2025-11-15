#include <iostream>

// 关系运算符重载
class Person {
 public:
  Person() {}

  Person(std::string name, int age) : m_Name(name), m_Age(age) {}

  bool operator==(const Person& p) {
    if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
      return true;
    }

    return false;
  }

  bool operator!=(const Person& p) {
    if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
      return false;
    }

    return true;
  }

  std::string m_Name;
  int m_Age;
};

void test01() {
  Person p1("Tom", 18);
  Person p2("Tom", 18);
  if (p1 == p2) {
    std::cout << "p1 和 p2 是相等的" << std::endl;
  } else {
    std::cout << "p1 和 p2 是不等的" << std::endl;
  }

  if (p1 != p2) {
    std::cout << "p1 和 p2 是不等的" << std::endl;
  } else {
    std::cout << "p1 和 p2 是相等的" << std::endl;
  }
}

int main() {
  test01();

  return 0;
}