#include <iostream>

// 赋值运算符重载
class Person {
 public:
  Person() {}

  Person(int age) { this->m_Age = new int(age); }

  ~Person() {
    if (m_Age != nullptr) {
      delete m_Age;

      m_Age = nullptr;
    }
  }

  // 重载赋值运算符
  Person& operator=(Person& p) {
    // 先判断是否有属性在堆区
    // 如果有先释放干净，再深拷贝
    if (this->m_Age != nullptr) {
      delete this->m_Age;

      this->m_Age = nullptr;
    }

    // 深拷贝
    this->m_Age = new int(*p.m_Age);

    return p;
  }

  // private:
  int* m_Age;
};

void test01() {
  Person p1(18);
  std::cout << "p1 的年龄：" << *p1.m_Age << std::endl;

  Person p2(28);
  std::cout << "p2 的年龄：" << *p2.m_Age << std::endl;

  // 赋值操作
  p2 = p1;

  std::cout << "p1 的年龄：" << *p1.m_Age << std::endl;
  std::cout << "p2 的年龄：" << *p2.m_Age << std::endl;

  Person p3(38);
  std::cout << "p3 的年龄：" << *p3.m_Age << std::endl;

  p3 = p2 = p1;

  std::cout << "p1 的年龄：" << *p1.m_Age << std::endl;
  std::cout << "p2 的年龄：" << *p2.m_Age << std::endl;
  std::cout << "p3 的年龄：" << *p3.m_Age << std::endl;
}

int main() {
  test01();

  int a = 10;
  int b = 20;
  int c = 30;

  c = b = a;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;

  return 0;
}