#include <iostream>

// 成员函数做友元

class Building;

class GoodGay {
 public:
  GoodGay();

  // 让 visit 函数可以访问 Building 中私有成员
  void visit();

  // 让 visit02 函数不可访问 Building 中私有成员
  void visit02();

  Building* m_Building;
};

class Building {
  // 告诉编译器 GoodGay 类下的 visit
  // 成员函数作为本类的好朋友，可以访问本类的私有属性
  friend void GoodGay::visit();

 public:
  Building();

  std::string m_SittingRoom;

 private:
  std::string m_BedRoom;
};

Building::Building() {
  this->m_SittingRoom = "客厅";
  this->m_BedRoom = "卧室";
}

GoodGay::GoodGay() { this->m_Building = new Building; }

void GoodGay::visit() {
  std::cout << "visit 函数正在访问：" << m_Building->m_SittingRoom << std::endl;
  std::cout << "visit 函数正在访问：" << m_Building->m_BedRoom << std::endl;
};

void GoodGay::visit02() {
  std::cout << "visit 函数正在访问：" << m_Building->m_SittingRoom << std::endl;
  // std::cout << "visit 函数正在访问：" << m_Building->m_BedRoom << std::endl;
};

void test01() {
  GoodGay gg;
  gg.visit();
  gg.visit02();
}

int main() {
  test01();

  return 0;
}