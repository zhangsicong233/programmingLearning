#include <fstream>
#include <iostream>

// 二进制文件 写文件
// 1、包含头文件 fstream

class Person {
 public:
  char m_Name[64];
  int m_Age;
};

void test01() {
  // 2、创建流对象
  std::ofstream ofs("person.txt", std::ios::out | std::ios::binary);

  // 3、打开文件
  // ofs.open("person.txt", std::ios::out | std::ios::binary);

  // 4、写文件
  Person p = {"张三", 18};
  ofs.write((const char*)&p, sizeof(Person));

  // 5、关闭文件
  ofs.close();
}

int main() {
  test01();

  return 0;
}