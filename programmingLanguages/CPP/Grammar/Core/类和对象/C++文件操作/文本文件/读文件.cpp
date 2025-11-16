#include <fstream>
#include <iostream>

// 文本文件 读文件

// 1、包含头文件 fstream
void test01() {
  // 2、创建流对象
  std::ifstream ifs;

  // 3、打开文件 并判断是否打开成功
  ifs.open("./test.txt", std::ios::in);
  if (!ifs.is_open()) {
    std::cout << "文件打开失败" << std::endl;

    return;
  }

  // 4、读文件
  // 4.1
  /*
  char buf[1024] = {0};
  while (ifs >> buf) {
    std::cout << buf << std::endl;
  }
  */

  // 4.2
  /*
  char buf[1024] = {0};
  while (ifs.getline(buf, sizeof(buf))) {
    std::cout << buf << std::endl;
  }
  */

  // 4.3
  /*
  std::string buf;
  while (getline(ifs, buf)) {
    std::cout << buf << std::endl;
  }
  */

  // 4.4
  char c;
  while ((c = ifs.get()) != EOF) {  // EOF end of file
    std::cout << c;
  }

  // 5、关闭文件
  ifs.close();
}

int main() {
  test01();

  return 0;
}