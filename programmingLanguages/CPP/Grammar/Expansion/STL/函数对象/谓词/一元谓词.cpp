#include <algorithm>
#include <iostream>
#include <vector>

// 返回 bool 类型的仿函数称为谓词
// 一元谓词

class GreaterFive {
 public:
  bool operator()(int val) {
    if (val > 5) {
      return true;
    } else {
      return false;
    }
  }
};

void test01() {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  // 查找容器中有没有大于 5 的数字
  std::vector<int>::iterator it =
      std::find_if(v.begin(), v.end(), GreaterFive());
  if (it == v.end()) {
    std::cout << "未找到" << std::endl;
  } else {
    std::cout << "找到了大于 5 的数字为：" << *it << std::endl;
  }
}

int main() {
  test01();

  return 0;
}