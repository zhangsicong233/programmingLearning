#include <iostream>

// 类模板与继承

template <class T>
class Base {
 public:
  Base() {}

  T m;
};

// class Son : public Base<int>  // 错误，必须要知道父类中 T 类型，
// 才能继承给子类
class Son : public Base<int> {
 public:
  Son() {}
};

// 如果想灵活指定父类中 T 类型，子类也需要变成模板
template <class T1, class T2>
class Son02 : public Base<T2> {
 public:
  Son02() {
    std::cout << "T1 的类型为：" << typeid(T1).name() << std::endl;
    std::cout << "T2 的类型为：" << typeid(T2).name() << std::endl;
  }

  T1 obj;
};

void test01() { Son s1; }

void test02() { Son02<int, char> s2; }

int main() {
  // test01();
  test02();

  return 0;
}