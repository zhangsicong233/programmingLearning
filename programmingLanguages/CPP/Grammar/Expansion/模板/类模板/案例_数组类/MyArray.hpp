#pragma once
#include <iostream>

template <class T>
class MyArray {
 public:
  MyArray() {
    this->m_Size = 0;
    this->m_Capacity = 0;
    this->pAddress = nullptr;
  }

  MyArray(int capacity) {
    this->m_Size = 0;
    this->m_Capacity = capacity;
    pAddress = new T[this->m_Capacity];
  }

  ~MyArray() {
    if (this->pAddress != nullptr) {
      delete[] this->pAddress;

      this->pAddress = nullptr;
    }
  }

  MyArray(const MyArray& arr) {
    this->m_Size = arr.m_Size;
    this->m_Capacity = arr.m_Capacity;

    this->pAddress = new T[arr.m_Capacity];

    for (int i = 0; i < this->m_Size; ++i) {
      this->pAddress[i] = arr.pAddress[i];
    }
  }

  MyArray& operator=(const MyArray& arr) {
    // 先判断原来堆区是否有数据，如果有，先释放
    if (this->pAddress != nullptr) {
      delete[] this->pAddress;

      pAddress = nullptr;

      this->m_Size = 0;
      this->m_Capacity = 0;
    }

    this->m_Size = arr.m_Size;
    this->m_Capacity = arr.m_Capacity;

    this->pAddress = new T[arr.m_Capacity];

    for (int i = 0; i < this->m_Size; ++i) {
      this->pAddress[i] = arr.pAddress[i];
    }

    return *this;
  }

  // 尾插法
  void pushBack(T& val) {
    if (this->m_Size == this->m_Capacity) {
      return;
    }

    this->pAddress[this->m_Size] = val;

    ++this->m_Size;
  }

  // 尾删法
  void popBack() {
    if (this->m_Size == 0) {
      return;
    }

    --this->m_Size;
  }

  // 通过下标方式访问数据元素
  T& operator[](int idx) { return this->pAddress[idx]; }

  // 返回数组容量
  int getCapacity() { return this->m_Capacity; }

  // 返回数组大小
  int getSize() { return this->m_Size; }

 private:
  T* pAddress;     // 指针指向堆区开辟的真实数组
  int m_Capacity;  // 数组容量
  int m_Size;      // 数组大小
};