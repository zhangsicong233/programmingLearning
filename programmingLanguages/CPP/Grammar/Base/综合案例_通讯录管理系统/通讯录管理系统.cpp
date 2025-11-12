#include <iostream>
#define MAX 1000

// 设计联系人结构体
struct Person {
  std::string m_Name;   // 姓名
  int m_Sex;            // 性别 1.男 2.女
  int m_Age;            // 年龄
  std::string m_Phone;  // 电话
  std::string m_Addr;   // 住址
};

// 设计通讯录结构体
struct Addressbooks {
  Person personArr[MAX];  // 通讯录中保存的联系人数组
  int m_Size;             // 通讯录人员个数
};

// 菜单界面
void showMenu() {
  std::cout << "***********************" << std::endl;
  std::cout << "***  " << "1. 添加联系人" << "  ***" << std::endl;
  std::cout << "***  " << "2. 显示联系人" << "  ***" << std::endl;
  std::cout << "***  " << "3. 删除联系人" << "  ***" << std::endl;
  std::cout << "***  " << "4. 查找联系人" << "  ***" << std::endl;
  std::cout << "***  " << "5. 修改联系人" << "  ***" << std::endl;
  std::cout << "***  " << "6. 清空联系人" << "  ***" << std::endl;
  std::cout << "***  " << "0. 退出通讯录" << "  ***" << std::endl;
  std::cout << "***********************" << std::endl;
}

// 1.添加联系人
void addPerson(Addressbooks* abs) {
  if (abs->m_Size == MAX) {
    std::cout << "通讯录已满，无法添加" << std::endl;

    return;
  } else {
    std::string name = "";
    std::cout << "请输入姓名：";
    std::cin >> name;
    abs->personArr[abs->m_Size].m_Name = name;

    int sex = -1;
    do {
      std::cout << "请输入性别（1.男 2.女）：";
      std::cin >> sex;

      if (sex == 1 || sex == 2) {
        abs->personArr[abs->m_Size].m_Sex = sex;
      } else {
        std::cout << "请重新输入" << std::endl;
      }
    } while (sex != 1 && sex != 2);

    int age = -1;
    do {
      std::cout << "请输入年龄（0 ~ 130）：";
      std::cin >> age;

      if (age >= 0 && age <= 130) {
        abs->personArr[abs->m_Size].m_Age = age;
      } else {
        std::cout << "请重新输入" << std::endl;
      }
    } while (age < 0 || age > 130);

    std::string phone = "";
    std::cout << "请输入联系电话：";
    std::cin >> phone;
    abs->personArr[abs->m_Size].m_Phone = phone;

    std::string address = "";
    std::cout << "请输入家庭住址：";
    std::cin >> address;
    abs->personArr[abs->m_Size].m_Addr = address;

    ++abs->m_Size;

    std::cout << "添加成功" << std::endl;
  }
}

// 2.显示联系人
void showPerson(const Addressbooks* abs) {
  if (abs->m_Size == 0) {
    std::cout << "当前记录为空" << std::endl;
  } else {
    for (int i = 0; i < abs->m_Size; ++i) {
      std::cout << "姓名：" << abs->personArr[i].m_Name << '\t';
      std::cout << "性别：" << (abs->personArr[i].m_Sex == 1 ? "男" : "女")
                << '\t';
      std::cout << "年龄：" << abs->personArr[i].m_Age << '\t';
      std::cout << "联系电话：" << abs->personArr[i].m_Phone << '\t';
      std::cout << "家庭住址：" << abs->personArr[i].m_Addr << std::endl;
    }
  }
}

// 检测联系人是否存在，存在则返回所在位置，不存在返回 -1
int isExist(const Addressbooks* abs, std::string name) {
  for (int i = 0; i < abs->m_Size; ++i) {
    if (abs->personArr[i].m_Name == name) {
      return i;
    }
  }

  return -1;
}

// 3.删除联系人
void deletePerson(Addressbooks* abs) {
  std::string name = "";
  std::cout << "请输入需要删除的联系人的姓名：";
  std::cin >> name;

  int idx = isExist(abs, name);
  if (idx == -1) {
    std::cout << "查无此人" << std::endl;
  } else {
    for (int i = idx; i < abs->m_Size; ++i) {
      abs->personArr[i] = abs->personArr[i + 1];
    }

    --abs->m_Size;

    std::cout << "已删除该联系人" << std::endl;
  }
}

// 4.查找联系人
void findPerson(const Addressbooks* abs) {
  std::string name = "";
  std::cout << "请输入需要查找的联系人的姓名：";
  std::cin >> name;

  int idx = isExist(abs, name);
  if (idx == -1) {
    std::cout << "查无此人" << std::endl;
  } else {
    std::cout << "姓名：" << abs->personArr[idx].m_Name << '\t';
    std::cout << "性别：" << (abs->personArr[idx].m_Sex == 1 ? "男" : "女")
              << '\t';
    std::cout << "年龄：" << abs->personArr[idx].m_Age << '\t';
    std::cout << "联系电话：" << abs->personArr[idx].m_Phone << '\t';
    std::cout << "家庭住址：" << abs->personArr[idx].m_Addr << std::endl;
  }
}

// 5.修改联系人
void modifyPerson(Addressbooks* abs) {
  std::string name = "";
  std::cout << "请输入需要修改的联系人的姓名：";
  std::cin >> name;

  int idx = isExist(abs, name);
  if (idx == -1) {
    std::cout << "查无此人" << std::endl;
  } else {
    std::string name = "";
    std::cout << "请输入姓名：";
    std::cin >> name;
    abs->personArr[idx].m_Name = name;

    int sex = -1;
    do {
      std::cout << "请输入性别（1.男 2.女）：";
      std::cin >> sex;

      if (sex == 1 || sex == 2) {
        abs->personArr[idx].m_Sex = sex;
      } else {
        std::cout << "请重新输入" << std::endl;
      }
    } while (sex != 1 && sex != 2);

    int age = -1;
    do {
      std::cout << "请输入年龄（0 ~ 130）：";
      std::cin >> age;

      if (age >= 0 && age <= 130) {
        abs->personArr[idx].m_Age = age;
      } else {
        std::cout << "请重新输入" << std::endl;
      }
    } while (age < 0 || age > 130);

    std::string phone = "";
    std::cout << "请输入联系电话：";
    std::cin >> phone;
    abs->personArr[idx].m_Phone = phone;

    std::string address = "";
    std::cout << "请输入家庭住址：";
    std::cin >> address;
    abs->personArr[idx].m_Addr = address;
  }
}

// 6.清空联系人
void clearPerson(Addressbooks* abs) {
  int flag = 0;
  std::cout << "是否确认清空（1.是，0.否）：";
  std::cin >> flag;

  if (flag) {
    abs->m_Size = 0;

    std::cout << "通讯录已清空" << std::endl;
  } else {
    std::cout << "已放弃清空" << std::endl;
  }
}

int main() {
  // 创建通讯录结构体变量
  Addressbooks abs;
  abs.m_Size = 0;

  int select = 0;
  do {
    showMenu();

    std::cin >> select;
    switch (select) {
        // 添加联系人
      case 1: {
        addPerson(&abs);
      }

      break;

        // 显示联系人
      case 2: {
        showPerson(&abs);
      }

      break;

        // 删除联系人
      case 3: {
        deletePerson(&abs);
      }

      break;

        // 查找联系人
      case 4: {
        findPerson(&abs);
      }

      break;

        // 修改联系人
      case 5: {
        modifyPerson(&abs);
      }

      break;

        // 清空联系人
      case 6: {
        clearPerson(&abs);
      }

      break;

        // 退出通讯录
      case 0: {
        std::cout << "欢迎下次使用" << std::endl;
      }

      break;

      default:
        break;
    }

    system("pause");
    system("cls");
  } while (select != 0);

  return 0;
}