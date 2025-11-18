#include <iostream>
#include <typeinfo>

// 类模板对象做函数参数

template <class T1, class T2>
class Person {
 public:
  Person() {}

  Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  void showPerson() {
    std::cout << "姓名：" << this->m_Name << std::endl;
    std::cout << "年龄：" << this->m_Age << std::endl;
  }

  T1 m_Name;
  T2 m_Age;
};

// 1、指定传入类型
void printPerson01(Person<std::string, int>& p) { p.showPerson(); }

void test01() {
  Person<std::string, int> p("Tom", 18);

  printPerson01(p);
}

// 2、参数模板化
template <class T1, class T2>
void printPerson02(Person<T1, T2>& p) {
  p.showPerson();

  std::cout << "T1 的类型为：" << typeid(T1).name() << std::endl;
  std::cout << "T2 的类型为：" << typeid(T2).name() << std::endl;
}

void test02() {
  Person<std::string, int> p("Jerry", 20);

  printPerson02(p);
}

// 3、整个类模板化
template <class T>
void printPerson03(T& p) {
  p.showPerson();

  std::cout << "T 的类型为：" << typeid(T).name() << std::endl;
}

void test03() {
  Person<std::string, int> p("hhh", 30);

  printPerson03(p);
}

int main() {
  // test01();
  // test02();
  test03();

  return 0;
}