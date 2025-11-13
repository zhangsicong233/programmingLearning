#include <iostream>

// 构造函数的调用规则
// 1、创建一个类，C++ 编译器会给每一个类添加至少三个函数
// 默认构造 (空实现)
// 析构 (空实现)
// 拷贝构造 (值拷贝)

// 2、调用规则
// 2.1、如果写了有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造
// 2.2、如果写了拷贝构造函数，编译器就不再提供其他普通构造函数

class Person {
 public:
  // Person() { std::cout << "Person 默认构造函数调用" << std::endl; }

  /*
  Person(int age) {
    this->m_Age = age;

    std::cout << "Person 有参构造函数调用" << std::endl;
  }
  */

  Person(const Person& p) {
    this->m_Age = p.m_Age;

    std::cout << "Person 拷贝构造函数调用" << std::endl;
  }

  ~Person() { std::cout << "Person 析构函数调用" << std::endl; }

  int m_Age;
};

/*
void test01() {
  Person p;
  p.m_Age = 18;

  Person p2(p);

  std::cout << "p2 的年龄为：" << p2.m_Age << std::endl;
}
*/

/*
void test02() {
  Person p(28);
  Person p2(p);

  std::cout << "p2 的年龄为：" << p2.m_Age << std::endl;
}
*/

void test03() {
  // Person p;
  // Person p(38);
}

int main() {
  // test01();
  // test02();

  return 0;
}