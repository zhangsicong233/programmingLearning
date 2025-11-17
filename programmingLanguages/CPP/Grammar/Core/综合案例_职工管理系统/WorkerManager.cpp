#include "WorkerManager.h"

WorkerManager::WorkerManager() {
  std::ifstream ifs;
  ifs.open(FILENAME, std::ios::in);

  if (!ifs.is_open()) {
    this->m_EmpNum = 0;
    this->m_EmpArray = nullptr;
    this->m_FileIsEmpty = true;

    ifs.close();

    return;
  }

  char ch;
  ifs >> ch;

  if (ifs.eof()) {
    this->m_EmpNum = 0;
    this->m_EmpArray = nullptr;
    this->m_FileIsEmpty = true;

    ifs.close();

    return;
  }

  int num = this->getEmpNum();
  this->m_EmpNum = num;
  this->m_EmpArray = new Worker*[this->m_EmpNum];

  this->initEmp();
}

WorkerManager::~WorkerManager() {
  if (this->m_EmpArray != nullptr) {
    for (int i = 0; i < this->m_EmpNum; ++i) {
      if (this->m_EmpArray[i] != nullptr) {
        delete this->m_EmpArray[i];

        this->m_EmpArray[i] = nullptr;
      }
    }
  }

  delete[] this->m_EmpArray;

  this->m_EmpArray = nullptr;
}

void WorkerManager::showMenu() {
  std::cout << "***********************************" << std::endl;
  std::cout << "*******欢迎使用职工管理系统!*******" << std::endl;
  std::cout << "**********1.增加职工信息***********" << std::endl;
  std::cout << "**********2.显示职工信息***********" << std::endl;
  std::cout << "**********3.删除离职职工***********" << std::endl;
  std::cout << "**********4.修改职工信息***********" << std::endl;
  std::cout << "**********5.查找职工信息***********" << std::endl;
  std::cout << "**********6.按照编号排序***********" << std::endl;
  std::cout << "**********7.清空所有文档***********" << std::endl;
  std::cout << "**********0.退出管理系统***********" << std::endl;
  std::cout << "***********************************" << std::endl;
  std::cout << std::endl;
}

void WorkerManager::exitSystem() { std::cout << "欢迎下次使用" << std::endl; }

void WorkerManager::addEmp() {
  int addNum = -1;
  std::cout << "请输入添加职工的数量：" << std::endl;
  std::cin >> addNum;

  if (addNum > 0) {
    int newSize = this->m_EmpNum + addNum;
    Worker** newSpace = new Worker*[newSize];

    if (this->m_EmpArray != nullptr) {
      for (int i = 0; i < this->m_EmpNum; ++i) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    for (int i = 0; i < addNum; ++i) {
      int id;
      std::string name;
      int deptId;
      std::cout << "请输入第 " << i + 1 << " 个新职工编号：" << std::endl;
      std::cin >> id;
      std::cout << "请输入第 " << i + 1 << " 个新职工姓名：" << std::endl;
      std::cin >> name;
      std::cout << "请选择该职工岗位：" << std::endl;
      std::cout << "1、老板" << std::endl;
      std::cout << "2、经理" << std::endl;
      std::cout << "3、员工" << std::endl;
      std::cin >> deptId;

      Worker* worker = nullptr;
      switch (deptId) {
        case 1: {
          worker = new Boss(id, name, deptId);
        }

        break;

        case 2: {
          worker = new Manager(id, name, deptId);
        }

        break;

        case 3: {
          worker = new Employee(id, name, deptId);
        }

        break;

        default:
          break;
      }

      newSpace[this->m_EmpNum + i] = worker;
    }

    delete[] this->m_EmpArray;

    this->m_EmpArray = newSpace;
    this->m_EmpNum = newSize;

    std::cout << "成功添加 " << addNum << " 名新职工" << std::endl;

    this->saveToFile();
    this->m_FileIsEmpty = false;
  } else {
    std::cout << "输入数据有误" << std::endl;
  }
}

void WorkerManager::saveToFile() {
  std::ofstream ofs;
  ofs.open(FILENAME, std::ios::out);

  for (int i = 0; i < this->m_EmpNum; ++i) {
    ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name
        << " " << this->m_EmpArray[i]->m_DeptId << std::endl;
  }

  ofs.close();
}

int WorkerManager::getEmpNum() {
  std::ifstream ifs;
  ifs.open(FILENAME, std::ios::in);

  int id;
  std::string name;
  int deptId;

  int cnt = 0;
  while (ifs >> id && ifs >> name && ifs >> deptId) {
    ++cnt;
  }

  return cnt;
}

void WorkerManager::initEmp() {
  std::ifstream ifs;
  ifs.open(FILENAME, std::ios::in);

  int id;
  std::string name;
  int deptId;

  int idx = 0;
  while (ifs >> id && ifs >> name && ifs >> deptId) {
    Worker* worker = nullptr;

    if (deptId == 1) {
      worker = new Boss(id, name, deptId);
    } else if (deptId == 2) {
      worker = new Manager(id, name, deptId);
    } else if (deptId == 3) {
      worker = new Employee(id, name, deptId);
    }

    this->m_EmpArray[idx] = worker;

    ++idx;
  }

  ifs.close();
}

void WorkerManager::showEmp() {
  if (this->m_FileIsEmpty) {
    std::cout << "文件不存在/记录为空" << std::endl;
  } else {
    for (int i = 0; i < this->m_EmpNum; ++i) {
      this->m_EmpArray[i]->showInfo();
    }
  }
}

int WorkerManager::empIsExist(int id) {
  int idx = -1;
  for (int i = 0; i < this->m_EmpNum; ++i) {
    if (this->m_EmpArray[i]->m_Id == id) {
      idx = i;

      return idx;
    }
  }

  return idx;
}

void WorkerManager::deleteEmp() {
  if (this->m_FileIsEmpty) {
    std::cout << "文件不存在/记录为空" << std::endl;
  } else {
    int id;
    std::cout << "请输入想要删除职工编号：";
    std::cin >> id;

    int idx = empIsExist(id);
    if (idx != -1) {
      for (int i = idx; i < this->m_EmpNum - 1; ++i) {
        this->m_EmpArray[i] = this->m_EmpArray[i + 1];
      }

      --this->m_EmpNum;

      std::cout << "删除成功" << std::endl;

      this->saveToFile();
    } else {
      std::cout << "删除失败，未找到职工" << std::endl;
    }
  }
}

void WorkerManager::modifyEmp() {
  if (this->m_FileIsEmpty) {
    std::cout << "文件不存在/记录为空" << std::endl;
  } else {
    int id;
    std::cout << "请输入修改职工的编号：";
    std::cin >> id;

    int idx = this->empIsExist(id);
    if (idx != -1) {
      delete this->m_EmpArray[idx];

      int newId;
      std::string newName;
      int newDeptId;

      std::cout << "查找到 " << id << " 号职工，请输入新职工号：";
      std::cin >> newId;
      std::cout << "请输入新姓名：";
      std::cin >> newName;
      std::cout << "请输入新岗位：" << std::endl;
      std::cout << "1、老板" << std::endl;
      std::cout << "2、经理" << std::endl;
      std::cout << "3、员工" << std::endl;
      std::cin >> newDeptId;

      Worker* worker = nullptr;
      switch (newDeptId) {
        case 1: {
          worker = new Boss(newId, newName, newDeptId);
        }

        break;

        case 2: {
          worker = new Manager(newId, newName, newDeptId);
        }

        break;

        case 3: {
          worker = new Employee(newId, newName, newDeptId);
        }

        break;

        default:
          break;
      }

      this->m_EmpArray[idx] = worker;

      std::cout << "修改成功" << std::endl;

      this->saveToFile();
    } else {
      std::cout << "查无此人, 修改失败" << std::endl;
    }
  }
}

void WorkerManager::findEmp() {
  if (this->m_FileIsEmpty) {
    std::cout << "文件不存在/记录为空" << std::endl;
  } else {
    int select = -1;
    std::cout << "请输入查找方式：" << std::endl;
    std::cout << "1、按职工编号查找" << std::endl;
    std::cout << "2、按职工姓名查找" << std::endl;
    std::cin >> select;

    switch (select) {
      case 1: {
        int id;
        std::cout << "请输入查找的职工编号：";
        std::cin >> id;

        int idx = this->empIsExist(id);
        if (idx != -1) {
          std::cout << "该职工信息如下：" << std::endl;

          this->m_EmpArray[idx]->showInfo();
        } else {
          std::cout << "查无此人" << std::endl;
        }
      }

      break;

      case 2: {
        std::string name;
        std::cout << "请输入查找的职工姓名：";
        std::cin >> name;

        bool flag = false;
        for (int i = 0; i < this->m_EmpNum; ++i) {
          if (this->m_EmpArray[i]->m_Name == name) {
            std::cout << "该职工信息如下：" << std::endl;

            this->m_EmpArray[i]->showInfo();

            flag = true;
          }
        }

        if (!flag) {
          std::cout << "查无此人" << std::endl;
        }
      }

      break;

      default:
        std::cout << "输入选项有误" << std::endl;

        break;
    }
  }
}

void WorkerManager::sortEmp() {
  if (this->m_FileIsEmpty) {
    std::cout << "文件不存在/记录为空" << std::endl;
  } else {
    int select;
    std::cout << "请选择排序方式：" << std::endl;
    std::cout << "1、按职工号升序" << std::endl;
    std::cout << "2、按职工号降序" << std::endl;
    std::cin >> select;

    for (int i = 0; i < this->m_EmpNum; ++i) {
      int minOrMax = i;
      for (int j = i + 1; j < this->m_EmpNum; ++j) {
        if (select == 1) {
          if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
            minOrMax = j;
          }
        } else {
          if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
            minOrMax = j;
          }
        }
      }

      if (i != minOrMax) {
        Worker* temp = this->m_EmpArray[i];
        this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
        this->m_EmpArray[minOrMax] = temp;
      }
    }

    std::cout << "排序成功, 排序后的结果为：" << std::endl;
    this->showEmp();

    this->saveToFile();
  }
}

void WorkerManager::clearFile() {
  int select = -1;
  std::cout << "确认清空" << std::endl;
  std::cout << "1、确认" << std::endl;
  std::cout << "2、返回" << std::endl;
  std::cin >> select;

  if (select == 1) {
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::trunc);

    if (this->m_EmpArray != nullptr) {
      for (int i = 0; i < this->m_EmpNum; ++i) {
        delete this->m_EmpArray[i];

        this->m_EmpArray[i] = nullptr;
      }
    }

    this->m_EmpNum = 0;
    this->m_FileIsEmpty = true;

    delete[] this->m_EmpArray;

    this->m_EmpArray = nullptr;

    std::cout << "清空成功" << std::endl;
  }
}