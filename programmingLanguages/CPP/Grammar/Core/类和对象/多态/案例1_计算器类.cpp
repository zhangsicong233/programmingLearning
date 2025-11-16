#include <iostream>

// 分别利用普通写法和多态技术实现计算器
class Calculator {
 public:
  int getResult(std::string oper) {
    if (oper == "+") {
      return this->m_Num1 + this->m_Num2;
    }

    if (oper == "-") {
      return this->m_Num1 - this->m_Num2;
    }

    if (oper == "*") {
      return this->m_Num1 * this->m_Num2;
    }

    // 如果想扩展新的功能，需要修改源码
    // 在真实的开发中 提倡 开闭原则
    // 开闭原则：对扩展进行开放，对修改进行关闭

    return -1;
  }

  // 两个操作数
  int m_Num1;
  int m_Num2;
};

// 利用多态实现计算器
// 实现计算器基类
class AbstractCalculator {
 public:
  virtual int getResult() { return 0; }

  int m_Num1;
  int m_Num2;
};

// 加法计算器
class AddCalculator : public AbstractCalculator {
 public:
  int getResult() { return m_Num1 + m_Num2; }
};

// 减法计算器
class SubCalculator : public AbstractCalculator {
 public:
  int getResult() { return m_Num1 - m_Num2; }
};

// 乘法计算器
class MulCalculator : public AbstractCalculator {
 public:
  int getResult() { return m_Num1 * m_Num2; }
};

void test01() {
  Calculator cal;
  cal.m_Num1 = 10;
  cal.m_Num2 = 20;

  std::cout << cal.m_Num1 << " + " << cal.m_Num2 << " = " << cal.getResult("+")
            << std::endl;
  std::cout << cal.m_Num1 << " - " << cal.m_Num2 << " = " << cal.getResult("-")
            << std::endl;
  std::cout << cal.m_Num1 << " * " << cal.m_Num2 << " = " << cal.getResult("*")
            << std::endl;
}

void test02() {
  // 加法运算
  AbstractCalculator* abc = new AddCalculator;
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;

  std::cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult()
            << std::endl;

  // 用完后记得销毁
  delete abc;

  // 减法运算
  abc = new SubCalculator;
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;

  std::cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult()
            << std::endl;

  delete abc;

  // 乘法运算
  abc = new MulCalculator;
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;

  std::cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult()
            << std::endl;

  delete abc;
}

// 多态好处
// 1、组织结构清晰
// 2、可读性强
// 3、对于前期和后期扩展以及维护性高

int main() {
  // test01();
  test02();

  return 0;
}