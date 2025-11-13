#include <iostream>

class Cube {
 public:
  void setL(double l) { this->m_L = l; }
  double getL() const { return this->m_L; }

  void setW(double w) { this->m_W = w; }
  double getW() const { return this->m_W; }

  void setH(double h) { this->m_H = h; }
  double getH() const { return this->m_H; }

  // 计算面积
  double calculateS() {
    return 2 * (this->m_L * this->m_W + this->m_L * this->m_H +
                this->m_W * this->m_H);
  }

  // 计算体积
  double calculateV() { return this->m_L * this->m_W * this->m_H; }

  bool isSameByClass(const Cube& other) {
    if (this->m_L == other.getL() && m_W == other.getW() &&
        m_H == other.getH()) {
      return 1;
    } else {
      return 0;
    }

    return 0;
  }

 private:
  double m_L;  // 长
  double m_W;  // 宽
  double m_H;  // 高
};

// 利用全局函数判断两个立方体是否相等
bool isSame(const Cube* c1, const Cube* c2) {
  if (c1->getL() == c2->getL() && c1->getW() == c2->getW() &&
      c1->getH() == c2->getH()) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // 创建立方体对象
  Cube c1;
  c1.setL(10);
  c1.setW(10);
  c1.setH(10);

  std::cout << "c1 的面积为：" << c1.calculateS() << std::endl;
  std::cout << "c1 的体积为：" << c1.calculateV() << std::endl;

  // 创建第二个立方体
  Cube c2;
  c2.setL(10);
  c2.setW(10);
  c2.setH(10);

  std::cout << "通过全局函数判断" << std::endl;
  if (isSame(&c1, &c2)) {
    std::cout << "相同" << std::endl;
  } else {
    std::cout << "不同" << std::endl;
  }

  std::cout << "通过成员函数判断" << std::endl;
  if (c1.isSameByClass(c2)) {
    std::cout << "相同" << std::endl;
  } else {
    std::cout << "不同" << std::endl;
  }

  return 0;
}