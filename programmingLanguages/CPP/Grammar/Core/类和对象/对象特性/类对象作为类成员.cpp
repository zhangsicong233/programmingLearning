#include <iostream>

// 类对象作为类成员

// 手机类
class Phone {
 public:
  Phone() {}

  // Phone m_Phone = pName;  // 隐式转换法
  Phone(std::string pName) {
    std::cout << "Phone 有参构造调用" << std::endl;

    this->m_PName = pName;
  }

  ~Phone() { std::cout << "Phone 析构函数调用" << std::endl; }

  // 品牌
  std::string m_PName;
};

// 人类
class Person {
 public:
  Person() {}

  Person(std::string name, std::string pName) : m_Name(name), m_Phone(pName) {
    std::cout << "Person 有参构造调用" << std::endl;
  }

  ~Person() { std::cout << "Person 析构函数调用" << std::endl; }

  // 姓名
  std::string m_Name;
  // 手机
  Phone m_Phone;
};

// 当其他类对象作为本类成员
// 构造时先构造类对象，再构造自身
// 析构时先析构自身，再析构类对象

void test01() {
  Person p("张三", "苹果MAX");

  std::cout << p.m_Name << "拿着" << p.m_Phone.m_PName << std::endl;
}

int main() {
  test01();

  return 0;
}