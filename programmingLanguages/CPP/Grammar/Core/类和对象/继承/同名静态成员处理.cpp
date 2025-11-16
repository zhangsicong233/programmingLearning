#include <iostream>

// 同名静态成员处理

class Base {
 public:
  static int m_A;

  static void func() {
    std::cout << "Base - static void func() 调用" << std::endl;
  }

  static void func(int a) {
    std::cout << "Base - static void func(int a) 调用" << std::endl;
  }
};

int Base::m_A = 100;

class Son : public Base {
 public:
  static int m_A;

  static void func() {
    std::cout << "Son - static void func() 调用" << std::endl;
  }
};

int Son::m_A = 200;

// 同名静态成员属性
void test01() {
  // 1、通过对象访问
  std::cout << "通过对象访问" << std::endl;
  Son s;
  std::cout << "Son 下 m_A = " << s.m_A << std::endl;
  std::cout << "Base 下 m_A = " << s.Base::m_A << std::endl;

  // 2、通过类名访问
  std::cout << "通过类名访问" << std::endl;
  std::cout << "Son 下 m_A = " << Son::m_A << std::endl;
  // 第一个 :: 代表通过类名的方式访问
  // 第二个 :: 代表访问父类作用域下
  std::cout << "Base 下 m_A = " << Son::Base::m_A << std::endl;
}

// 同名静态成员函数
void test02() {
  // 通过对象访问
  std::cout << "通过对象访问" << std::endl;
  Son s;
  s.func();
  s.Base::func();

  // 通过类名方式访问
  std::cout << "通过类名访问" << std::endl;
  Son::func();
  Son::Base::func();

  // 子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
  // 如果想访问父类中被隐藏的童名成员，需要加作用域
  Son::Base::func(100);
}

int main() {
  // test01();
  test02();

  return 0;
}