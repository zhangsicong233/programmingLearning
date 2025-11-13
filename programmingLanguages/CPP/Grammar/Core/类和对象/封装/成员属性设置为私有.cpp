#include <iostream>

// 成员属性设置为私有
// 1、可以自己控制读写权限
// 2、对于写可以检测数据有效性

// 人类
class Person {
 public:
  // 设置姓名
  void setName(std::string name) { this->m_Name = name; }

  // 获取姓名
  std::string getName() { return this->m_Name; }

  // 获取年龄
  int getAge() { return this->m_Age; }

  // 设置偶像
  void setIdol(std::string idol) { this->m_Idol = idol; }

 private:
  // 姓名  可读可写
  std::string m_Name;

  // 年龄  只读
  int m_Age = 18;

  // 偶像  只写
  std::string m_Idol;
};

int main() {
  Person p;
  // 姓名设置
  p.setName("张三");
  // 获取姓名
  std::cout << "姓名：" << p.getName() << std::endl;

  // 年龄设置
  /*
  p.setAge(20);
  p.m_Age = 20;
  */
  // 只读状态，外界无法设置
  // 获取年龄
  std::cout << "年龄：" << p.getAge() << std::endl;

  // 偶像设置
  p.setIdol("鸽鸽");
  // 获取偶像
  /*
  std::cout << "偶像：" << p.m_idol << std::endl;
  std::cout << "偶像：" << p.getIdol() << std::endl;
  */
  // 只写状态，外界无法访问

  return 0;
}