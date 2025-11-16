#include <iostream>

class AbstractCPU {
 public:
  ~AbstractCPU() {}
  virtual void calculator() = 0;
};

class AbstractVideoCard {
 public:
  virtual void display() = 0;
};

class AbstractMemory {
 public:
  virtual void storage() = 0;
};

class InterCPU : public AbstractCPU {
 public:
  void calculator() { std::cout << "Inter 的 CPU 正在计算" << std::endl; }
};

class AMDCPU : public AbstractCPU {
 public:
  void calculator() { std::cout << "AMD 的 CPU 正在计算" << std::endl; }
};

class NVIDIAVideoCard : public AbstractVideoCard {
 public:
  void display() { std::cout << "NVIDIA 的显卡正在显示" << std::endl; }
};

class AMDVideoCard : public AbstractVideoCard {
 public:
  void display() { std::cout << "AMD 的显卡正在显示" << std::endl; }
};

class SamsungMemory : public AbstractMemory {
 public:
  void storage() { std::cout << "三星的内存条正在存储" << std::endl; }
};

class HynixMemory : public AbstractMemory {
 public:
  void storage() { std::cout << "海力士的内存条正在存储" << std::endl; }
};

class Computer {
 public:
  Computer() {}

  Computer(AbstractCPU* cpu, AbstractVideoCard* vc, AbstractMemory* mem) {
    this->m_Cpu = cpu;
    this->m_Vc = vc;
    this->m_Mem = mem;
  }

  ~Computer() {
    if (m_Cpu != nullptr) {
      delete m_Cpu;

      m_Cpu = nullptr;
    }

    if (m_Vc != nullptr) {
      delete m_Vc;

      m_Vc = nullptr;
    }

    if (m_Mem != nullptr) {
      delete m_Mem;

      m_Mem = nullptr;
    }
  }

  void doWork() {
    m_Cpu->calculator();
    m_Vc->display();
    m_Mem->storage();
  }

 private:
  AbstractCPU* m_Cpu;
  AbstractVideoCard* m_Vc;
  AbstractMemory* m_Mem;
};

void test01() {
  AbstractCPU* interCpu = new InterCPU;
  AbstractCPU* amdCpu = new AMDCPU;
  AbstractVideoCard* amdVideoCard = new AMDVideoCard;
  AbstractVideoCard* nvidiaVideoCard = new NVIDIAVideoCard;
  AbstractMemory* samsungMemory = new SamsungMemory;
  AbstractMemory* hynixMemory = new HynixMemory;

  std::cout << "第一台电脑开始工作" << std::endl;
  Computer* computer01 = new Computer(interCpu, amdVideoCard, samsungMemory);
  computer01->doWork();

  delete computer01;

  std::cout << "----------------------------------------" << std::endl;

  std::cout << "第二台电脑开始工作" << std::endl;
  Computer* computer02 =
      new Computer(new AMDCPU, new NVIDIAVideoCard, new HynixMemory);
  computer02->doWork();

  delete computer02;

  std::cout << "----------------------------------------" << std::endl;

  std::cout << "第三台电脑开始工作" << std::endl;
  Computer* computer03 =
      new Computer(new AMDCPU, new NVIDIAVideoCard, new SamsungMemory);
  computer03->doWork();

  delete computer03;
}

int main() {
  test01();

  return 0;
}