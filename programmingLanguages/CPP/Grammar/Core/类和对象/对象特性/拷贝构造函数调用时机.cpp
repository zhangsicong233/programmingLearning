#include <iostream>

// 拷贝构造函数调用时机

class Person {
 public:
  Person() { std::cout << "Person 默认构造函数调用" << std::endl; }

  Person(int age) {
    this->m_Age = age;

    std::cout << "Person 有参构造函数调用" << std::endl;
  }

  Person(const Person& p) {
    this->m_Age = p.m_Age;

    std::cout << "Person 拷贝构造函数调用" << std::endl;
  }

  ~Person() { std::cout << "Person 析构函数调用" << std::endl; }

  int m_Age;
};

// 1、使用一个已经创建完毕的对象来初始化另一个对象
void test01() {
  Person p1(20);
  Person p2(p1);

  std::cout << "p2 的年龄：" << p2.m_Age << std::endl;
}

// 2、值传递的方式给函数参数传值
void doWork(Person p) {}

void test02() {
  Person p;
  doWork(p);
}

// 3、值的方式返回局部变量
Person doWork02() {
  Person p1;

  std::cout << reinterpret_cast<uintptr_t>(&p1) << std::endl;

  return Person(p1);
}

void test03() {
  Person p = doWork02();
  std::cout << reinterpret_cast<uintptr_t>(&p) << std::endl;
}

int main() {
  // test01();
  // test02();
  test03();

  return 0;
}