#include <iostream>

// 构造函数的分类及调用
// 分类
//  按参数分类  无参构造和有参构造
//  按类型分类  普通构造和拷贝构造
class Person {
 public:
  Person() { std::cout << "无参构造(默认构造)函数 Person() 调用" << std::endl; }
  Person(int a) {
    this->m_Age = a;

    std::cout << "有参构造函数 Person(int a) 调用" << std::endl;
  }
  // 拷贝构造函数
  Person(const Person& p) {
    // 将传入的人身上的所有属性，拷贝到我身上
    this->m_Age = p.m_Age;

    std::cout << "拷贝构造函数 Person(cosnt Person& p) 调用" << std::endl;
  }

  ~Person() { std::cout << "析构函数 ~Person() 调用" << std::endl; }

  // private:
  int m_Age;
};

void test01() {
  // 调用
  // 1、括号法
  Person p1;      // 默认构造函数调用
  Person p2(10);  // 有参构造函数调用
  Person p3(p2);  // 拷贝构造函数调用

  /*
  std::cout << "p2 的年龄为：" << p2.m_Age << std::endl;
  std::cout << "p3 的年龄为：" << p3.m_Age << std::endl;
  */

  // 注意事项 1
  // 调用默认构造函数时，不要加（）
  // 因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象
  // Person p();  // 不会执行

  // 2、显示法
  Person p4;
  Person p5 = Person(10);  // 有参构造
  Person p6 = Person(p5);  // 拷贝构造

  // 匿名对象  特点：当前行执行结束后，系统会立即回收掉匿名对象
  /*
  std::cout << "-----" << std::endl;
  Person(10);
  std::cout << "-----" << std::endl;
  */

  // 注意事项 2
  // 不要利用拷贝构造函数 初始化匿名对象
  // 编译器会认为 Person (p5) === Person p5;  对象声明
  // Person(p5);

  // 3、隐式转换法
  Person p7 = 10;  // 相当于 Person p4 = Person(10);  有参构造
  Person p8 = p7;  // 拷贝构造
}

int main() {
  test01();

  return 0;
}