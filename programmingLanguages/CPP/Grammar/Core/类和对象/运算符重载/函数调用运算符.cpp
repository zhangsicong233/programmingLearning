#include <iostream>

// 函数调用运算符重载

class MyPrint {
 public:
  MyPrint() {}

  void operator()(std::string test) { std::cout << test << std::endl; }
};

// 仿函数非常灵活，没有固定的写法
// 加法类
class MyAdd {
 public:
  int operator()(int num1, int num2) { return num1 + num2; }
};

void MyPrint02(std::string test) { std::cout << test << std::endl; }

void test01() {
  MyPrint myPrint;

  // 由于使用起来非常类似于函数调用，因此称为仿函数
  myPrint("hello world");
  MyPrint02("hello world");
}

void test02() {
  MyAdd myAdd;
  int res = myAdd(100, 200);
  std::cout << "res = " << res << std::endl;

  // 匿名函数对象
  std::cout << MyAdd()(100, 300) << std::endl;
}

int main() {
  // test01();
  test02();

  return 0;
}