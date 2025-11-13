#include <iostream>

// 深拷贝与浅拷贝

class Person {
 public:
  Person() { std::cout << "Person 默认构造函数调用" << std::endl; }

  Person(int age, int height) {
    std::cout << "Person 有参构造函数调用" << std::endl;

    this->m_Age = age;
    this->m_Height = new int(height);
  }

  // 自己实现拷贝构造函数，解决浅拷贝带来的问题
  Person(const Person& p) {
    std::cout << "Person 拷贝构造函数调用" << std::endl;

    this->m_Age = p.m_Age;
    // this->m_Height = p.m_Height  编译器默认实现就是这行代码
    // 深拷贝
    this->m_Height = new int(*p.m_Height);
  }

  ~Person() {
    std::cout << "Person 析构函数调用" << std::endl;

    // 析构代码，将堆区开辟的数据做释放操作
    if (m_Height != nullptr) {
      delete m_Height;

      m_Height = nullptr;
    }
  }

  int m_Age;      // 年龄
  int* m_Height;  // 身高
};

void test01() {
  Person p1(18, 160);

  std::cout << "p1 的年龄：" << p1.m_Age << std::endl;
  std::cout << "p1 的身高：" << *p1.m_Height << std::endl;

  Person p2(p1);

  std::cout << "p2 的年龄：" << p2.m_Age << std::endl;
  std::cout << "p2 的身高：" << *p2.m_Height << std::endl;
}

// 总结：如果属性又在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

int main() {
  test01();

  return 0;
}