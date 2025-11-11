#include <iostream>

// 结构体指针
// 定义学生结构体
struct Student {
  std::string name;  // 姓名
  int age;           // 年龄
  int score;         // 成绩
};

int main() {
  // 1、创建学生结构体变量
  Student stu = {"zsc", 21, 100};

  // 2、通过指针指向结构体变量
  Student* stuPtr = &stu;

  // 3、通过指针访问结构体变量中的数据
  // 通过结构体指针访问结构体中的属性，需要用 ->
  std::cout << "姓名：" << stuPtr->name << '\t' << "年龄：" << stuPtr->age
            << '\t' << "分数：" << stuPtr->score << std::endl;

  return 0;
}