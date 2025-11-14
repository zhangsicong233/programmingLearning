#include <iostream>

// 类做友元

class Building;

class GoodGay {
 public:
  GoodGay();

  // 参观函数访问 Building 中的属性
  void visit();

  Building* m_Building;
};

class Building {
  // GoodGay 类是本类的好朋友，可以访问本类的私有属性
  friend class GoodGay;

 public:
  Building();

  std::string m_SittingRoom;

 private:
  std::string m_BedRoome;
};

// 类外写成员函数
Building::Building() {
  this->m_SittingRoom = "客厅";
  this->m_BedRoome = "卧室";
};

GoodGay::GoodGay() {
  // 创建一个建筑物对象

  this->m_Building = new Building;
}

void GoodGay::visit() {
  std::cout << "好基友类正在访问：" << m_Building->m_SittingRoom << std::endl;

  std::cout << "好基友类正在访问：" << m_Building->m_BedRoome << std::endl;
}

void test01() {
  GoodGay gg;
  gg.visit();
}

int main() {
  test01();

  return 0;
}