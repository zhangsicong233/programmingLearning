#include <iostream>

// 访问权限
// 1、公共权限  public      成员类内可以访问 类外可以访问
// 2、保护权限  protected   成员类内可以访问 类外不可访问
// 儿子可以访问父亲中的保护内容
// 3、私有权限  private     成员类内可以访问类外不可访问
// 儿子不可访问父亲中的私有内容

class Person {
 public:
  void func() {
    this->m_Name = "张三";
    this->m_Car = "拖拉机";
    this->m_Password = "123456";
  }

  // 公共权限
 public:
  // 姓名
  std::string m_Name;

  // 保护权限
 protected:
  // 汽车
  std::string m_Car;

  // 私有权限
 private:
  // 密码
  std::string m_Password;
};

int main() {
  // 实例化具体对象
  Person p;
  p.m_Name = "李四";
  // p.m_Car = "奔驰";  // 保护权限内容，类外访问不到
  // p.m_Password = "666666";  // 私有权限内容，类外访问不到

  return 0;
}