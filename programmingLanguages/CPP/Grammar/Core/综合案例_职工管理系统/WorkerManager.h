#pragma once
#include <fstream>
#include <iostream>

#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include "Worker.h"

#define FILENAME "./EmpFile.txt"

class WorkerManager {
 public:
  WorkerManager();

  ~WorkerManager();

  void showMenu();

  void exitSystem();

  void addEmp();

  void saveToFile();

  int getEmpNum();

  void initEmp();

  void showEmp();

  int empIsExist(int id);

  void deleteEmp();

  void modifyEmp();

  void findEmp();

  void sortEmp();

  void clearFile();

  int m_EmpNum;
  Worker** m_EmpArray;

  bool m_FileIsEmpty;
};