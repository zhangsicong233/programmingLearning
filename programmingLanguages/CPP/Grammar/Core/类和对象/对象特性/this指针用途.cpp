#include <iostream>

// this 指针的用途

class Person {
 public:
  // this 指针指向的是被调用的成员函数所属的对象
  Person(int age) { this->age = age; }

  Person& PersonAddAge(Person& p) {
    this->age += p.age;

    // this 是指向 p2 的指针， *this 指向的就是 p2 这个本体
    return *this;
  }

  int age;
};

// 1、解决名称冲突
void test01() {
  Person p1(18);
  std::cout << "p1 的年龄：" << p1.age << std::endl;
}

// 2、返回对象本身用 *this
void test02() {
  Person p1(10);
  Person p2(10);

  p2.PersonAddAge(p1);
  std::cout << "p2 的年龄为：" << p2.age << std::endl;

  p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
  std::cout << "p2 的年龄为：" << p2.age << std::endl;
}

int main() {
  // test01();
  test02();

  return 0;
}