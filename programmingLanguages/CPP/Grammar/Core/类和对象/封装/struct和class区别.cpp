#include <iostream>

// struct 和 class 区别
// struct 默认权限是公共
// class 默认权限是私有

class C1 {
  // 默认权限是  私有
  int m_A;
};

struct C2 {
  // 默认权限是  公共
  int m_A;
};

int main() {
  C1 c1;
  // c1.m_A = 100;  // class 中 m_A 默认权限为私有 不可访问

  C2 c2;
  c2.m_A = 100;  // struct 中 m_A 默认权限为公共 可以访问

  return 0;
}