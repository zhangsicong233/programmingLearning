#include <iostream>

// 结构体数组
// 1、定义结构体
struct Student {
  // 姓名
  std::string name;
  // 年龄
  int age;
  // 分数
  int score;
};

int main() {
  // 2、创建结构体数组
  Student stuArr[3] = {{"张三", 18, 100}, {"李四", 28, 99}, {"王五", 38, 66}};

  // 3、给结构体数组中元素赋值
  stuArr[2].name = "赵六";
  stuArr[2].age = 80;
  stuArr[2].score = 60;

  // 4、遍历结构体数组
  for (int i = 0; i < 3; ++i) {
    std::cout << "姓名：" << stuArr[i].name << '\t' << "年龄：" << stuArr[i].age
              << '\t' << "分数：" << stuArr[i].score << std::endl;
  }

  return 0;
}