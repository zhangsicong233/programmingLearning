#include <iostream>

struct Hero {
  std::string name;
  int age;
  std::string gender;
};

void bubbleSort(Hero* heroArr, int len) {
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (heroArr[j].age > heroArr[j + 1].age) {
        Hero temp = heroArr[j];
        heroArr[j] = heroArr[j + 1];
        heroArr[j + 1] = temp;
      }
    }
  }
}

void printInfo(const Hero* heroArr, int len) {
  for (int i = 0; i < len; ++i) {
    std::cout << "姓名：" << heroArr[i].name << '\t' << "年龄："
              << heroArr[i].age << '\t' << "性别：" << heroArr[i].gender
              << std::endl;
  }
}

int main() {
  Hero heroArr[5] = {{"刘备", 23, "男"},
                     {"关羽", 22, "男"},
                     {"张飞", 20, "男"},
                     {"赵云", 21, "男"},
                     {"貂蝉", 19, "女"}};

  bubbleSort(heroArr, 5);

  printInfo(heroArr, 5);

  return 0;
}