#include <iostream>

// 函数对象（仿函数）
class MyAdd {
 public:
  int operator()(int v1, int v2) { return v1 + v2; }
};

class MyPrint {
 public:
  MyPrint() { this->cnt = 0; }

  void operator()(std::string test) {
    std::cout << test << std::endl;

    ++this->cnt;
  }

  // 内部自己状态
  int cnt;
};

void doPrint(MyPrint& mp, std::string test) { mp(test); }

// 1、使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01() {
  MyAdd myAdd;
  std::cout << myAdd(10, 20) << std::endl;
}

// 2、函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02() {
  MyPrint myPrint;
  myPrint("hello world");

  std::cout << "myPrint 调用次数为：" << myPrint.cnt << std::endl;
}

// 3、函数对象可以作为参数传递
void test03() {
  MyPrint myPrint;
  doPrint(myPrint, "hello cpp");
}

int main() {
  // test01();
  // test02();
  test03();

  return 0;
}