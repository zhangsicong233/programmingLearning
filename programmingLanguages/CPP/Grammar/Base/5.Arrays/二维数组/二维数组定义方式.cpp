#include <iostream>

int main() {
  // 二维数组定义方式

  /*
      1. 数据类型  数组名[行数][列数];
      2. 数据类型  数组名[行数][列数] = {{数据1， 2}, {数据3， 4}};
      3. 数据类型  数组名[行数][列数] = {数据1， 2， 3， 4};
      4. 数据类型  数组名[][列数] = {数据1， 2， 3， 4};
 */

  // 1.
  int arr[2][3];
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[1][0] = 4;
  arr[1][1] = 5;
  arr[1][2] = 6;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // 2.
  int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << arr2[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // 3.
  int arr3[2][3] = {1, 2, 3, 4, 5, 6};

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << arr3[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // 4.
  int arr4[][3] = {1, 2, 3, 4, 5, 6};

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << arr4[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}