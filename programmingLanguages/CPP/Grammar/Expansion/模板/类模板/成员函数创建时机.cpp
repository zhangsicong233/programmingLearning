#include <iostream>

// 类模板中成员函数创建时机
// 类模板中成员函数调用时才去创建
class Person01 {
 public:
  Person01() {}

  void showPerson01() { std::cout << "Person01 show" << std::endl; }
};

class Person02 {
 public:
  Person02() {}

  void showPerson02() { std::cout << "Person02 show" << std::endl; }
};

template <class T>
class MyClass {
 public:
  MyClass() {}

  // 类模板中的成员函数
  void func01() { obj.showPerson01(); }

  void func02() { obj.showPerson02(); }

  T obj;
};

void test01() {
  MyClass<Person02> p1;
  // p1.func01();
  p1.func02();
}

int main() {
  test01();

  return 0;
}