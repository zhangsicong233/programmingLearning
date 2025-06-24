#include <iostream>

int main() {
  int arr[5] = {1, 3, 2, 5, 4};

  for (int i = 0, j = 4; i < j; ++i, --j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  for (auto num : arr) {
    std::cout << num << std::endl;
  }

  return 0;
}