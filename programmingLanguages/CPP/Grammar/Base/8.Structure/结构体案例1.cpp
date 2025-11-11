#include <ctime>
#include <iostream>

struct Student {
  std::string name;
  int score;
};

struct Teacher {
  std::string name;
  Student stuArr[5];
};

// 给老师和学生赋值的函数
void setInfo(Teacher* teacherArr, int len) {
  std::string nameSeed = "ABCDE";

  for (int i = 0; i < len; ++i) {
    teacherArr[i].name = "teacher_";
    teacherArr[i].name += nameSeed[i];
    for (int j = 0; j < 5; ++j) {
      teacherArr[i].stuArr[j].name = "student_";
      teacherArr[i].stuArr[j].name += nameSeed[j];

      int random = rand() % 41 + 60;
      teacherArr[i].stuArr[j].score = random;
    }
  }
}

// 打印老师和学生信息的函数
void printInfo(const Teacher* teacherArr, int len) {
  for (int i = 0; i < len; ++i) {
    std::cout << "老师姓名：" << teacherArr[i].name << std::endl;
    std::cout << "所带学生信息：" << std::endl;
    for (int j = 0; j < 5; ++j) {
      std::cout << "学生 " << j + 1 << " 姓名：" << teacherArr[i].stuArr[j].name
                << '\t' << "分数：" << teacherArr[i].stuArr[j].score
                << std::endl;
    }
    std::cout << std::endl;
  }
}

int main() {
  // 随机数种子
  srand((unsigned int)time(NULL));

  Teacher teacherArr[3];
  int len = sizeof(teacherArr) / sizeof(teacherArr[0]);

  setInfo(teacherArr, len);

  printInfo(teacherArr, len);

  return 0;
}