#pragma once

#include <iostream>
#include <string>
#include <type_traits>

template <typename T, typename Enable = void>
class Logger {
 public:
  static void log(const T& value) {
    std::cout << "Gengral Logger: " << value << std::endl;
  }
};

// 偏特化，当 T 是指针类型
template <typename T>
class Logger<T, typename std::enable_if_t<std::is_pointer_v<T>>> {
 public:
  static void log(const T& value) {
    if (value) {
      std::cout << "Pointer Logger: " << *value << std::endl;
    } else {
      std::cout << "Pointer Logger: nullptr" << std::endl;
    }
  }
};

// 全特化，当 T 是 std::string 类型
template <>
class Logger<std::string> {
 public:
  static void log(const std::string& value) {
    std::cout << "String Logger: " << value << std::endl;
  }
};

// 函数模板，用于递归调用 Logger::log
template <typename T>
void logOne(const T& value) {
  Logger<T>::log(value);
}

// 使用模板折叠表达式实现可变参数列表打印
template <typename... Args>
void logAll(const Args&... args) {
  (logOne(args), ...);
}