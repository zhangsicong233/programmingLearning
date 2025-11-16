#include <iostream>

class AbstractDrinking {
 public:
  virtual void boil() = 0;

  virtual void brew() = 0;

  virtual void pourInCup() = 0;

  virtual void putSomething() = 0;

  void makeDrink() {
    boil();
    brew();
    pourInCup();
    putSomething();
  }
};

class Coffee : public AbstractDrinking {
 public:
  void boil() override { std::cout << "煮水" << std::endl; }

  void brew() override { std::cout << "冲泡咖啡" << std::endl; }

  void pourInCup() override { std::cout << "倒入咖啡杯中" << std::endl; }

  void putSomething() override { std::cout << "加入糖和牛奶" << std::endl; }
};

class Tea : public AbstractDrinking {
 public:
  void boil() override { std::cout << "煮水" << std::endl; }

  void brew() override { std::cout << "冲泡茶叶" << std::endl; }

  void pourInCup() override { std::cout << "倒入茶杯中" << std::endl; }

  void putSomething() override { std::cout << "加入枸杞" << std::endl; }
};

// 制作
void doWork(AbstractDrinking* abs) {
  abs->makeDrink();

  if (abs != nullptr) {
    delete abs;

    abs = nullptr;
  }
}

void test01() {
  doWork(new Coffee);

  std::cout << "----------------" << std::endl;

  doWork(new Tea);
}

int main() {
  test01();

  return 0;
}