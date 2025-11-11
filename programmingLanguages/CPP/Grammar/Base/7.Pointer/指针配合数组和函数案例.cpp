#include <iostream>

// 封装一个函数，利用冒泡排序，实现对整型数组的升序排序

void bubbleSort(int* arr, int len) {
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};

  bubbleSort(arr, 10);

  for (auto i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}