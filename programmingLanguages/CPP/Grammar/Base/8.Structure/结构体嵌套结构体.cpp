#include <iostream>

// 结构体嵌套结构体

// 定义学生结构体
struct Student {
  std::string name;  // 学生姓名
  int age;           // 学生年龄
  int score;         // 学生成绩
};

// 定义老师结构体
struct Teacher {
  int id;            // 教师编号
  std::string name;  // 教师姓名
  int age;           // 教师年龄
  Student stu;       // 辅导的学生
};

int main() {
  // 创建老师
  Teacher t;
  t.id = 10000;
  t.name = "老王";
  t.age = 50;
  t.stu.name = "小王";
  t.stu.age = 20;
  t.stu.score = 60;

  std::cout << "老师姓名：" << t.name << '\n'
            << "老师编号：" << t.id << '\n'
            << "老师年龄：" << t.age << '\n'
            << "老师所带学生姓名：" << t.stu.name << '\n'
            << "学生年龄：" << t.stu.age << '\n'
            << "学生成绩：" << t.stu.score << std::endl;

  return 0;
}