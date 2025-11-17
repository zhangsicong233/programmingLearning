#include <cstdlib>
#include <iostream>

#include "WorkerManager.h"

int main() {
  WorkerManager wm;

  int choice = -1;
  do {
    wm.showMenu();
    std::cout << "请输入你的选择：";
    std::cin >> choice;

    switch (choice) {
    case 1: {
      wm.addEmp();
    }

    break;

    case 2: {
      wm.showEmp();
    }

    break;

    case 3: {
      wm.deleteEmp();
    }

    break;

    case 4: {
      wm.modifyEmp();
    }

    break;

    case 5: {
      wm.findEmp();
    }

    break;

    case 6: {
      wm.sortEmp();
    }

    break;

    case 7: {
      wm.clearFile();
    }

    break;

    case 0: {
      wm.exitSystem();
    }

    break;

    default:
      break;
    }

    system("bash -c 'read -p \"Press Enter to continue...\"'");
    system("clear");
  } while (choice);

  return 0;
}
