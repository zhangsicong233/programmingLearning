#include <iostream>

class Student {
  // 类中的属性和行为  统一称为  成员
  // 属性  成员属性 成员变量
  // 行为  成员函数 成员方法
 public:
  // 给姓名赋值
  void setName(std::string name) { this->m_Name = name; }

  // 给学号赋值
  void setId(std::string id) { this->m_Id = id; }

  void showStudent() {
    std::cout << "姓名：" << this->m_Name << '\t';
    std::cout << "学号：" << this->m_Id << std::endl;
  }

 public:
  std::string m_Name;
  std::string m_Id;
};

int main() {
  // 创建一个具体学生  实例化对象
  Student stu1;
  stu1.m_Name = "张三";
  stu1.m_Id = "1";

  stu1.showStudent();

  Student stu2;
  stu2.setName("李四");
  stu2.setId("2");

  stu2.showStudent();

  return 0;
}