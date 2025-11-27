#include "MyString.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

MyString::MyString() : _data(nullptr) {}

MyString::MyString(const char* str) {
  if (str) {
    _data = new char[std::strlen(str) + 1];
    std::strcpy(_data, str);
  } else {
    _data = new char[1];
    _data[0] = '\0';
  }
}

MyString::MyString(const MyString& other) {
  if (other._data) {
    _data = new char[std::strlen(other._data) + 1];
    std::strcpy(_data, other._data);
  } else {
    _data = nullptr;
  }
}

MyString& MyString::operator=(const MyString& other) {
  if (this != &other) {
    delete[] _data;

    if (other._data) {
      _data = new char[std::strlen(other._data)];
      std::strcpy(_data, other._data);
    } else {
      _data = nullptr;
    }
  }

  return *this;
}

void MyString::myPrint() {
  if (_data) {
    std::cout << _data << std::endl;
  } else {
    std::cout << "(null)" << std::endl;
  }
}

MyString::~MyString() {
  if (_data) {
    delete[] _data;

    _data = nullptr;
  }
}