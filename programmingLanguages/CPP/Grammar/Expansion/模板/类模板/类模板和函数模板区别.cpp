#include <iostream>

// 类模板与函数模板区别
template <class NameType, class AgeType = int>
class Person {
 public:
  Person() {}

  Person(NameType name, AgeType age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  void showPerson() {
    std::cout << "name = " << this->m_Name << std::endl;
    std::cout << "age = " << this->m_Age << std::endl;
  }

  NameType m_Name;
  AgeType m_Age;
};

// 1、类模板没有自动类型推导的使用方式
void test01() {
  // Person p("Tom", 999);  // 错误，无法用自动类型推导
  Person<std::string, int> p("Tom", 999);

  p.showPerson();
}

// 2、类模板在模板参数列表总可以有默认参数
void test02() {
  Person<std::string> p("Jerry", 666);

  p.showPerson();
}

int main() {
  // test01();
  test02();

  return 0;
}