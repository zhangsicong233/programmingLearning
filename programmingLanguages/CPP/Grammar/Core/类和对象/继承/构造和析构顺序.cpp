#include <iostream>

// 构造和析构顺序
class Base {
 public:
  Base() { std::cout << "Base 的构造函数" << std::endl; }

  ~Base() { std::cout << "Base 的析构函数" << std::endl; }
};

class Son : public Base {
 public:
  Son() { std::cout << "Son 的构造函数" << std::endl; }

  ~Son() { std::cout << "Son 的析构函数" << std::endl; }
};

// 继承中的构造和析构顺序如下：
// 先构造父类，再构造子类
// 析构的顺序与构造的顺序相反

void test01() { Son s; }

int main() {
  test01();

  return 0;
}