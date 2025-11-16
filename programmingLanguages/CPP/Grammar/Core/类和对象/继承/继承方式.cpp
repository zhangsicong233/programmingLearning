#include <iostream>

// 继承方式
// 公共继承
class Base1 {
 public:
  int m_A;

 protected:
  int m_B;

 private:
  int m_C;
};

class Son1 : public Base1 {
 public:
  void func() {
    // 父类中的公共权限成员  到子类中依然是公共权限
    m_A = 10;
    // 父类中的保护权限成员  到子类中依然是保护权限
    m_B = 20;
    // 父类中的私有权限成员  子类访问不到
    // m_C = 30;
  }
};

// 保护继承
class Base2 {
 public:
  int m_A;

 protected:
  int m_B;

 private:
  int m_C;
};

class Son2 : protected Base2 {
 public:
  void func() {
    // 父类中公共成员 通过保护继承 到子类中变为保护权限
    m_A = 10;
    // 父类中保护成员 通过保护继承 到子类中依然是保护权限
    m_B = 20;
    // m_C = 30; // 父类中私有成员 子类访问不到
  }
};

// 私有继承
class Base3 {
 public:
  int m_A;

 protected:
  int m_B;

 private:
  int m_C;
};

class Son3 : private Base3 {
 public:
  void func() {
    // 父类中公共成员 通过私有继承 到子类中变为私有权限
    m_A = 10;
    // 父类中保护成员 通过私有继承 到子类中变为私有权限
    m_B = 20;
    // m_C = 30; // 父类中私有成员 子类访问不到
  }
};

class GrandSon3 : public Son3 {
 public:
  void func() {
    // 到了 Son3 中 m_A,m_B 均变为私有，即使是儿子，也访问不到
    // m_A = 1000;
    // m_B = 1000;
  }
};

void test01() {
  Son1 s1;
  s1.m_A = 100;
  // s1.m_B = 200;  // 到 Son1 中 m_B 是保护权限 类外访问不到
}

void test02() {
  Son2 s2;
  // 在 Son2 中 m_A 变为保护权限 类外访问不到
  // s2.m_A = 100;
  // 在 Son2 中 m_B 为保护权限 类外访问不到
  // s2.m_B = 200;
}

void test03() {
  Son3 s3;
  // 在 Son3 中 m_A 变为私有权限 类外访问不到
  // s3.m_A = 100;
  // 在 Son3 中 m_B 为私有权限 类外访问不到
  // s3.m_B = 200;
}

int main() { return 0; }