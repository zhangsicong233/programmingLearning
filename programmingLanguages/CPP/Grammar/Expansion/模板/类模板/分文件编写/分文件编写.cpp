#include <iostream>

#include "Person.hpp"

// 类模板分文件编写问题以及解决

// 解决方法
// 将 .h 和 .cpp 中的内容写到一起，将后缀名改为 .hpp

/*
template <class T1, class T2>
class Person {
 public:
  Person() {}

  Person(T1 name, T2 age);

  void showPerson();

  T1 m_Name;
  T2 m_Age;
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
  this->m_Name = name;
  this->m_Age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson() {
  std::cout << "姓名：" << this->m_Name << std::endl;
  std::cout << "年龄：" << this->m_Age << std::endl;
}
*/

void test01() {
  Person p("Tom", 18);

  p.showPerson();
}

int main() {
  test01();

  return 0;
}