#include <iostream>

// 结构体做函数参数

// 将学生传入到一个参数中，打印学生身上所有信息
// 定义学生结构体
struct Student {
  std::string name;  // 学生姓名
  int age;           // 学生年龄
  int score;         // 学生成绩
};

// 打印学生信息函数
// 1、值传递
void printStu1(Student stu) {
  stu.age = 100;

  std::cout << "在子函数 1 中打印" << std::endl;
  std::cout << "姓名：" << stu.name << '\t' << "年龄：" << stu.age << '\t'
            << "分数：" << stu.score << std::endl;
}

// 2、地址传递
void printStu2(Student* stu) {
  stu->age = 200;

  std::cout << "在子函数 2 中打印" << std::endl;
  std::cout << "姓名：" << stu->name << '\t' << "年龄：" << stu->age << '\t'
            << "分数：" << stu->score << std::endl;
}

int main() {
  // 创建结构体变量
  Student stu = {"张三", 18, 100};

  printStu1(stu);

  printStu2(&stu);

  std::cout << "在 main 函数中打印" << std::endl;
  std::cout << "姓名：" << stu.name << '\t' << "年龄：" << stu.age << '\t'
            << "分数：" << stu.score << std::endl;

  return 0;
}