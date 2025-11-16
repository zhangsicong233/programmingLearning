#include <iostream>

// 纯虚函数和抽象类
class Base {
 public:
  // 纯虚函数
  // 只要有一个纯虚函数，这个类称为抽象类
  // 抽象类特点
  // 1、无法实例化对象
  // 2、抽象类的子类必须要重写父类中的纯虚函数，否则也属于抽象类
  virtual void func() = 0;
};

class Son : public Base {
 public:
  void func() override { std::cout << "func() 调用" << std::endl; }
};

void test01() {
  // 抽象类无法实例化对象
  /*
  Base b;
  new Base;
  */

  // 子类必须要重写父类中的纯虚函数，否则无法实例化对象
  Base* base = new Son;
  base->func();
}

int main() {
  test01();

  return 0;
}