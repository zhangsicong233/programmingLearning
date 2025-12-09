#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <mutex>

template <typename T>
class Singleton {
 public:
  static std::shared_ptr<T> GetInstance() {
    std::call_once(_flag, []() { _instance = std::shared_ptr<T>(new T); });

    return _instance;
  }

  void PrintAddress() { std::cout << _instance.get() << std::endl; }

 protected:
  Singleton() = default;

  Singleton(const Singleton<T>& other) = delete;
  Singleton& operator=(const Singleton<T>& other) = delete;

  ~Singleton() { std::cout << "this is singleton destruct" << std::endl; }

 private:
  static std::once_flag _flag;
  static std::shared_ptr<T> _instance;
};

template <typename T>
std::once_flag Singleton<T>::_flag;

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;