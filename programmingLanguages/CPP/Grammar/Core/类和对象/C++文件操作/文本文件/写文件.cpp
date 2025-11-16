#include <fstream>
#include <iostream>

// 文本文件 写文件
// 1、包含头文件 fstream
void test01() {
  // 2、创建流对象
  std::ofstream ofs;
  // 3、指定打开方式
  ofs.open("./test.txt", std::ios::out);

  // 4、写内容
  ofs << "姓名：张三" << std::endl;
  ofs << "性别：男" << std::endl;
  ofs << "年龄: 18" << std::endl;

  // 关闭文件
  ofs.close();
}

int main() {
  test01();

  return 0;
}