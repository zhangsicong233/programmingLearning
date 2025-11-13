#include <iostream>

// const 修饰成员函数

// 常函数
class Person {
 public:
  Person() {}

  // this 指针的本质是 指针常量 ———— 指向不可修改，所指内容可修改
  // const Person* const this
  // 在成员函数后加 const 修饰的是 this 指针，让指针指向的值也不可以修改
  void showPerson() const {
    // this->m_A = 100;  // 错误：不能在常函数中修改普通成员变量
    this->m_B = 100;  // 正确：mutable 成员可以在常函数中修改
    // this = nullptr  // this 指针不可修改指针的指向
  }

  void func() {}

  int m_A;
  mutable int
      m_B;  // 特殊变量，即使在常函数中，也可以修改这个值    加上关键字 mutable
};

void test01() {
  Person p;
  p.showPerson();
}

// 常对象
void test02() {
  // 在对象前加 const 变为常对象
  const Person p{};  // 使用值初始化
  // p.m_A = 100;    // 错误：常对象不能修改普通成员变量
  p.m_B = 100;  // m_B 是一个特殊的值，在常对象下也可修改

  // 常对象只能调用常函数
  p.showPerson();
  // p.func(); // 常对象不可以调用普通成员函数， 因为普通成员函数可以修改属性
}

int main() {
  test01();
  test02();

  return 0;
}