#include <iostream>

// 继承中同名成员处理

class Base {
 public:
  Base() { this->m_A = 100; }

  void func() { std::cout << "Base - func() 调用" << std::endl; }

  void func(int a) { std::cout << "Son - func(int a) 调用" << std::endl; }

  int m_A;
};

class Son : public Base {
 public:
  Son() { m_A = 200; }

  void func() { std::cout << "Son - func() 调用" << std::endl; }

  int m_A;
};

// 同名成员属性处理方式
void test01() {
  Son s;
  std::cout << "Son 下 m_A = " << s.m_A << std::endl;
  // 如果通过子类对象 访问到父类中的同名成员 需要加父类作用域
  std::cout << "Base 下 m_A = " << s.Base::m_A << std::endl;
}

// 同名函数处理方式
void test02() {
  Son s;
  // 直接调用，调用的是子类的同名成员
  s.func();

  // 如何调用到父类中同名成员函数？
  s.Base::func();

  // 如果子类中出现了和父类同名的成员函数，
  // 子类的同名成员会隐藏掉父类中所有的同名成员函数
  // 如果想访问父类中被隐藏的同名成员函数需要加作用域
  s.Base::func(1);
}

int main() {
  // test01();
  test02();

  return 0;
}