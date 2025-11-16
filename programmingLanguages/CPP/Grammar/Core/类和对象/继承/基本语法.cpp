#include <iostream>

// 普通实现页面
/*
// Java
class Java {
 public:
  void header() {
    std::cout << "首页、公开课、登录、注册 ... （公共头部)" << std::endl;
  }

  void footer() {
    std::cout << "帮助中心、交流合作、站内地图 ... （公共底部）" << std::endl;
  }

  void left() {
    std::cout << "Java、Python、C++、 ... （公共分类列表）" << std::endl;
  }

  void content() { std::cout << "Java 学科视频" << std::endl; }
};

// Python
class Python {
 public:
  void header() {
    std::cout << "首页、公开课、登录、注册 ... （公共头部)" << std::endl;
  }

  void footer() {
    std::cout << "帮助中心、交流合作、站内地图 ... （公共底部）" << std::endl;
  }

  void left() {
    std::cout << "Java、Python、C++、 ... （公共分类列表）" << std::endl;
  }

  void content() { std::cout << "Python 学科视频" << std::endl; }
};

// C++
class Cpp {
 public:
  void header() {
    std::cout << "首页、公开课、登录、注册 ... （公共头部)" << std::endl;
  }

  void footer() {
    std::cout << "帮助中心、交流合作、站内地图 ... （公共底部）" << std::endl;
  }

  void left() {
    std::cout << "Java、Python、C++、 ... （公共分类列表）" << std::endl;
  }

  void content() { std::cout << "C++ 学科视频" << std::endl; }
};
*/

// 继承实现页面
class BasePage {
 public:
  void header() {
    std::cout << "首页、公开课、登录、注册 ... （公共头部)" << std::endl;
  }

  void footer() {
    std::cout << "帮助中心、交流合作、站内地图 ... （公共底部）" << std::endl;
  }

  void left() {
    std::cout << "Java、Python、C++、 ... （公共分类列表）" << std::endl;
  }
};

// Java 页面
class Java : public BasePage {
 public:
  void content() { std::cout << "Java 学科视频" << std::endl; }
};

// Python 页面
class Python : public BasePage {
 public:
  void content() { std::cout << "python 学科视频" << std::endl; }
};

// CPP 页面
class CPP : public BasePage {
 public:
  void content() { std::cout << "c++ 学科视频" << std::endl; }
};

// 继承的好处：减少重复代码
// 语法： class 子类名 ： 继承方式（public/protect/private） 父类名
// 子类 也称为 派生类
// 父类 也成为 基类

void test01() {
  std::cout << "java 下载视频界面如下" << std::endl;
  Java j;
  j.header();
  j.footer();
  j.left();
  j.content();

  std::cout << "---------------------------------------------------"
            << std::endl;

  std::cout << "python 下载视频界面如下" << std::endl;
  Python py;
  py.header();
  py.footer();
  py.left();
  py.content();

  std::cout << "---------------------------------------------------"
            << std::endl;

  std::cout << "C++ 下载视频界面如下" << std::endl;
  CPP cpp;
  cpp.header();
  cpp.footer();
  cpp.left();
  cpp.content();
}

int main() {
  test01();

  return 0;
}