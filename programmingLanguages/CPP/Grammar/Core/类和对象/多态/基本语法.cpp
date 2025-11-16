#include <iostream>

// 多态基本语法

//  动物类
class Animal {
 public:
  // 虚函数
  virtual void speak() { std::cout << "动物在说话" << std::endl; }
};

// 猫类
class Cat : public Animal {
 public:
  // 重写   函数返回值类型 函数名 参数列表 完全相同
  void speak() { std::cout << "小猫在说话" << std::endl; }
};

// 狗类
class Dog : public Animal {
 public:
  void speak() { std::cout << "小狗在说话" << std::endl; }
};

// 执行说话的函数
// 地址早绑定 在编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定
void doSpeak(Animal& animal) { animal.speak(); }

// 动态多态满足条件
// 1、有继承关系
// 2、子类要重写父类的虚函数

// 动态多态使用
// 父类的指针/引用 指向子类对象

void test01() {
  Cat cat;
  // Animal& animal = cat
  doSpeak(cat);

  Dog dog;

  doSpeak(dog);
}

int main() {
  test01();

  return 0;
}