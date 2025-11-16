#include <fstream>
#include <iostream>

class Person {
 public:
  char m_Name[64];
  int m_Age;
};

void test01() {
  std::ifstream ifs;
  ifs.open("./person.txt", std::ios::in | std::ios::binary);
  if (!ifs.is_open()) {
    std::cout << "文件打开失败" << std::endl;

    return;
  }

  Person p;
  ifs.read((char*)&p, sizeof(Person));
  std::cout << "姓名：" << p.m_Name << std::endl;
  std::cout << "年龄：" << p.m_Age << std::endl;

  ifs.close();
}

int main() {
  test01();

  return 0;
}