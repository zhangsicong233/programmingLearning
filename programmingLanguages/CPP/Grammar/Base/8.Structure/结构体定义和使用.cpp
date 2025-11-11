#include <iostream>
#include <string>

// 自定义数据类型：一些类型集合组成的一个类型
// 语法: struct 类型名称（成员列表）

// 1、创建学生数据类型 : 学生包括（姓名，年龄，分数）
struct Student {
  // 成员列表

  // 姓名
  std::string name;
  // 年龄
  int age;
  // 考试分数
  int score;
} s3;  // 顺便创建结构体变量

int main() {
  // 2、通过学生类型创建具体学生
  // 创建时 struct 关键词可省略
  // 2.1 struct Student s1;
  struct Student s1;
  // 给 s1 属性赋值, 通过 . 访问结构体变量中的属性
  s1.name = "张三";
  s1.age = 18;
  s1.score = 100;
  std::cout << "姓名：" << s1.name << '\t' << "年龄：" << s1.age << '\t'
            << "分数：" << s1.score << std::endl;

  // 2.2 struct Student s2 = { ... };
  struct Student s2 = {"李四", 19, 80};
  std::cout << "姓名：" << s2.name << '\t' << "年龄：" << s2.age << '\t'
            << "分数：" << s2.score << std::endl;

  // 2.3 在定义结构体时顺便创建结构体变量
  // 不建议使用
  s3.name = "王五";
  s3.age = 20;
  s3.score = 60;
  std::cout << "姓名：" << s3.name << '\t' << "年龄：" << s3.age << '\t'
            << "分数：" << s3.score << std::endl;

  return 0;
}