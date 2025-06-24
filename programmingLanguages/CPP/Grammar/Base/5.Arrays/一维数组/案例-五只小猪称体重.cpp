#include <iostream>

int main() {
  int arr[5] = {300, 350, 200, 400, 250};

  int ans = -1;
  for (int i = 0; i < 5; ++i) {
    if (ans < arr[i]) {
      ans = arr[i];
    }
  }

  std::cout << "最重的小猪体重为：" << ans << std::endl;

  return 0;
}