#pragma once

class MyString {
 public:
  MyString();
  MyString(const char* str);
  MyString(const MyString& other);

  MyString& operator=(const MyString& other);

  void myPrint();

  ~MyString();

 private:
  char* _data;
};
