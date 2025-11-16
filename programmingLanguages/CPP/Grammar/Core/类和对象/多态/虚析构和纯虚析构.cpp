#include <iostream>

// 虚析构和纯虚析构
class Animal {
 public:
  Animal() { std::cout << "Animal 构造函数调用" << std::endl; }

  // 利用虚析构可以解决父类指针释放子类对象不干净的问题
  // virtual ~Animal() { std::cout << "Animal 析构函数调用" << std::endl; }
  // 纯虚析构  需要声明也需要实现
  // 有了纯虚析构后，这个类也属于抽象类，无法实例化对象
  virtual ~Animal() = 0;

  // 纯虚函数  需要声明不需要实现
  virtual void speak() = 0;
};

Animal::~Animal() { std::cout << "Animal 析构函数调用" << std::endl; }

class Cat : public Animal {
 public:
  Cat() {}

  Cat(std::string name) {
    std::cout << "Cat 构造函数调用" << std::endl;

    this->m_Name = new std::string(name);
  }

  ~Cat() {
    if (m_Name != nullptr) {
      std::cout << "Cat 析构函数调用" << std::endl;

      delete m_Name;

      m_Name = nullptr;
    }
  }

  void speak() { std::cout << *m_Name << " 小猫在说话" << std::endl; }

  std::string* m_Name;
};

void test01() {
  Animal* animal = new Cat("Tom");
  animal->speak();

  // 父类指针在析构时，不会调用子类中析构函数，导致子类如果有堆区数据，会出现内存泄漏
  delete animal;
}

int main() {
  test01();

  return 0;
}