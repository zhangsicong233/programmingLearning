#include <algorithm>
#include <iostream>
#include <vector>

// 二元谓词
class MyCmp {
 public:
  bool operator()(int x, int y) { return x > y; }
};

void test01() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(2);
  v.push_back(3);
  v.push_back(5);

  std::sort(v.begin(), v.end());

  for (auto val : v) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // 使用函数对象 改变算法策略，变为排序规则从大到小
  std::sort(v.begin(), v.end(), MyCmp());

  std::cout << "-----------------------------" << std::endl;
  for (auto val : v) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main() {
  test01();

  return 0;
}