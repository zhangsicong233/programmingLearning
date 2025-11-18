#include <iostream>

#include "MyArray.hpp"

class Person {
 public:
  Person() {}
  Person(std::string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  std::string m_Name;
  int m_Age;
};

void printPersonArray(MyArray<Person>& arr) {
  for (int i = 0; i < arr.getSize(); ++i) {
    std::cout << "姓名：" << arr[i].m_Name << "\t年龄：" << arr[i].m_Age
              << std::endl;
  }
}

void printIntArray(MyArray<int> arr) {
  for (int i = 0; i < arr.getSize(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void test01() {
  MyArray<int> intArr(5);

  for (int i = 0; i < 5; ++i) {
    // 利用尾插法向数组中插入数据
    intArr.pushBack(i);
  }

  std::cout << "intArr 的打印输出为：" << std::endl;
  printIntArray(intArr);

  std::cout << "intArr 的容量为：" << intArr.getCapacity() << std::endl;
  std::cout << "intArr 的大小为：" << intArr.getSize() << std::endl;

  MyArray<int> intArr02(intArr);

  std::cout << "intArr02 的打印输出为：" << std::endl;
  printIntArray(intArr02);

  // 尾删法
  intArr02.popBack();

  std::cout << "尾删后:a" << std::endl;
  std::cout << "intArr02 的容量为：" << intArr02.getCapacity() << std::endl;
  std::cout << "intArr02 的大小为：" << intArr02.getSize() << std::endl;
}

void test02() {
  MyArray<Person> personArr(10);

  Person p1("孙悟空", 999);
  Person p2("韩信", 30);
  Person p3("妲己", 20);
  Person p4("赵云", 25);
  Person p5("安其拉", 27);

  // 将数据插入到数组中
  personArr.pushBack(p1);
  personArr.pushBack(p2);
  personArr.pushBack(p3);
  personArr.pushBack(p4);
  personArr.pushBack(p5);

  printPersonArray(personArr);

  std::cout << "intArr02 的容量为：" << personArr.getCapacity() << std::endl;
  std::cout << "intArr02 的大小为：" << personArr.getSize() << std::endl;
}

int main() {
  // test01();
  test02();

  return 0;
}