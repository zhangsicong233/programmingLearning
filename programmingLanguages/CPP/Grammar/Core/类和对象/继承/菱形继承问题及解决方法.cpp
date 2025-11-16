#include <iostream>

// 菱形继承问题及解决方法

class Animal {
 public:
  int m_Age;
};

// 利用虚继承 解决菱形继承问题
// 继承之前加上关键字 virtual 变为虚继承
// Animal 类称为虚基类
// 羊类
class Sheep : virtual public Animal {
 public:
};

// 驼类
class Tuo : virtual public Animal {
 public:
};

// 羊驼类
class SheepTuo : public Sheep, public Tuo {
 public:
};

void test01() {
  SheepTuo st;
  st.Sheep::m_Age = 18;
  st.Tuo::m_Age = 28;

  // 当菱形继承，两个父类拥有相同数据，需要加作用域以区分
  std::cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << std::endl;
  std::cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << std::endl;
  std::cout << "st.m_Age = " << st.m_Age << std::endl;

  // 这份数据我们知道只需要一份，菱形继承导致数据有两份, 资源浪费
}

int main() {
  test01();

  return 0;
}