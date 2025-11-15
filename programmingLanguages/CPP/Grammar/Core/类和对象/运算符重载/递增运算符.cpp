#include <iostream>

// 递增运算符重载
// 实现个人的整型变量
class MyInteger {
  friend std::ostream& operator<<(std::ostream& myOut, const MyInteger& myInt);
  friend MyInteger& operator++(MyInteger& myInt);
  friend MyInteger operator++(MyInteger& myInt, int);

 public:
  MyInteger() { this->m_Num = 0; }

  MyInteger(int num) : m_Num(num) {}

 private:
  int m_Num;
};

std::ostream& operator<<(std::ostream& myOut, const MyInteger& myInt) {
  myOut << myInt.m_Num;

  return myOut;
}

// 重载前置 ++ 运算符  返回引用是为了一直对一个数据进行递增
MyInteger& operator++(MyInteger& myInt) {
  ++myInt.m_Num;

  return myInt;
}

// 重载后置 ++ 运算符
// int 代表占位参数，可以用于区分前置和后置递增
MyInteger operator++(MyInteger& myInt, int) {
  // 先 记录当时结果
  MyInteger temp = myInt;

  // 后 递增
  ++myInt.m_Num;

  // 最后 将记录结果返回
  return temp;
}

void test01() {
  MyInteger myInt;

  std::cout << ++myInt << std::endl;
}

void test02() {
  MyInteger myInt;

  std::cout << myInt++ << std::endl;
  std::cout << myInt << std::endl;
}

int main() {
  // test01();
  test02();

  return 0;
}