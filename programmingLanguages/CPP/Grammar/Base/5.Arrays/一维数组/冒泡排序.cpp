#include <iostream>

int main() {
  int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

  for (int i = 0; i < 9 - 1; ++i) {
    for (int j = 0; j < 9 - 1 - i; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (auto num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}