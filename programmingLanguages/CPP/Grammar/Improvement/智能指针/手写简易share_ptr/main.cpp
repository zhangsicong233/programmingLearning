#include <iostream>
#include <memory>

#include "SimpleSharedPtr.hpp"

class Student {
 public:
  Student() : _name("default"), _age(0) {}

  Student(const std::string& name, int age) : _name(name), _age(age) {
    std::cout << "有参" << std::endl;
  }

  ~Student() {}

  std::string _name;
  int _age;
};

int main() {
  SimpleSharedPtr<Student> ptr1;
  std::cout << ptr1.use_count() << std::endl;
  std::cout << "--------------------" << std::endl;

  SimpleSharedPtr<Student> ptr2(new Student("zsc", 22));
  std::cout << ptr2.use_count() << std::endl;
  std::cout << "--------------------" << std::endl;

  SimpleSharedPtr<Student> ptr3(ptr2);
  std::cout << ptr2.use_count() << std::endl;
  std::cout << ptr3.use_count() << std::endl;
  std::cout << "--------------------" << std::endl;

  ptr1 = ptr3;
  std::cout << ptr1.use_count() << std::endl;
  std::cout << ptr3.use_count() << std::endl;
  std::cout << "--------------------" << std::endl;

  ptr2.reset(new Student("lsr", 22));
  std::cout << ptr1.use_count() << std::endl;
  std::cout << ptr2.use_count() << std::endl;
  std::cout << ptr3.use_count() << std::endl;
  std::cout << "--------------------" << std::endl;

  return 0;
}