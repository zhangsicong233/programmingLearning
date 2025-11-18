#include <iostream>

// 通过全局函数 打印 Person 信息

// 提前让编译器知道 Person 存在
template <class T1, class T2>
class Person;

// 类外实现
template <class T1, class T2>
void printPerson(Person<T1, T2> p) {
  std::cout << "类外实现" << std::endl;
  std::cout << "姓名：" << p.m_Name << std::endl;
  std::cout << "年龄：" << p.m_Age << std::endl;
}

template <class T1, class T2>
class Person {
 public:
  // 全局函数 类内实现
  /*
  friend void printPerson(Person<T1, T2> p) {
    std::cout << "姓名：" << p.m_Name << std::endl;
    std::cout << "年龄：" << p.m_Age << std::endl;
  }
  */

  // 全局函数类外实现
  // 加空模板参数列表
  // 如果全局函数是类外实现，需要让 编译器提前知道这个函数存在
  friend void printPerson<>(Person<T1, T2> p);

  Person() {}

  Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
  }

 private:
  T1 m_Name;
  T2 m_Age;
};

// 全局函数在类内实现
void test01() {
  Person<std::string, int> p("Tom", 10);

  printPerson(p);
}

// 全局函数在类外实现
void test02() {
  Person<std::string, int> p("Jerry", 20);

  printPerson(p);
}

int main() {
  test01();

  return 0;
}