#include <iostream>

template <class T>
void mySwap(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

template <class T>
void mySort(T* arr, int len) {
  for (int i = 0; i < len; ++i) {
    int max = i;
    for (int j = i; j < len; ++j) {
      if (arr[max] < arr[j]) {
        max = j;
      }
    }

    if (max != i) {
      mySwap(arr[max], arr[i]);
    }
  }
}

template <class T>
void printArr(const T& arr, int len) {
  for (int i = 0; i < len; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void test01() {
  char charArr[] = "badcfe";
  int charLen = sizeof(charArr) / sizeof(charArr[0]);
  mySort(charArr, charLen);

  printArr(charArr, charLen);
}

void test02() {
  int intArr[] = {7, 5, 1, 3, 9, 2, 4};
  int len = sizeof(intArr) / sizeof(intArr[0]);

  mySort(intArr, len);

  printArr(intArr, len);
}

int main() {
  // test01();
  test02();

  return 0;
}