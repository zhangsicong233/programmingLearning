#include <iostream>

// const 使用场景

struct Student {
  std::string name;  // 学生姓名
  int age;           // 学生年龄
  int score;         // 学生成绩
};

// 将函数中的形参改为指针，可以减少内存空间(不会复制新的副本出来)
void printStu(const Student* stu) {
  // stu->age = 200;  // 加入 const 后，一旦有修改操作就会报错，可以防止误操作

  std::cout << "在子函数中打印" << std::endl;
  std::cout << "姓名：" << stu->name << '\t' << "年龄：" << stu->age << '\t'
            << "分数：" << stu->score << std::endl;
}

int main() {
  // 创建结构体变量
  struct Student stu = {"张三", 15, 70};

  // 通过函数打印结构体变量信息
  printStu(&stu);

  std::cout << "在 main 函数中打印" << std::endl;
  std::cout << "姓名：" << stu.name << '\t' << "年龄：" << stu.age << '\t'
            << "分数：" << stu.score << std::endl;

  return 0;
}