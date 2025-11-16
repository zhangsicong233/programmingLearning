#include <iostream>

// 多继承语法

class Base01 {
 public:
  Base01() {
    this->m_A = 100;
    this->same = 1000;
  }

  int m_A;
  int same;
};

class Base02 {
 public:
  Base02() {
    this->m_B = 200;
    this->same = 2000;
  }

  int m_B;
  int same;
};

// 子类 需要继承 Base01 和 Base02
// 语法： class 子类 : 继承方式 父类 1, 继承方式 父类 2, ...
class Son : public Base01, public Base02 {
 public:
  Son() {
    this->m_C = 300;
    this->m_D = 400;
  }

  int m_C;
  int m_D;
};

void test01() {
  Son s;
  std::cout << "size of Son = " << sizeof(Son) << std::endl;

  // 当父类中出现同名成员，需要加作用域区分
  std::cout << "Base01 下 same = " << s.Base01::same << std::endl;
  std::cout << "Base02 下 same = " << s.Base02::same << std::endl;
}

int main() {
  test01();

  return 0;
}