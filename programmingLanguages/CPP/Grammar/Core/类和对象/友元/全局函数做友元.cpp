#include <iostream>

// 全局函数做友元

// 建筑物类
class Building {
  // goodGay 全局函数是 Building 好朋友，可以访问 Building 成员
  friend void goodGay(const Building& build);

 public:
  Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
  }

  // 客厅
  std::string m_SittingRoom;

 private:
  // 卧室
  std::string m_BedRoom;
};

// 全局函数
void goodGay(const Building& build) {
  std::cout << "好基友的全局函数正在访问：" << build.m_SittingRoom << std::endl;

  std::cout << "好基友的全局函数正在访问：" << build.m_BedRoom << std::endl;
}

void test01() {
  Building build;

  goodGay(build);
}

int main() {
  test01();

  return 0;
}