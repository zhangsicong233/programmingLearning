#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class Log {
 public:
  Log(const Log& other) = delete;
  Log& operator=(const Log& other) = delete;

  static Log* getInstance() {
    static std::once_flag flag;
    std::call_once(flag, []() { _instance = new Log(); });

    return _instance;
  }

  void printLog(const std::string& msg) {
    std::cout << __TIME__ << " " << msg << std::endl;
  }

 private:
  static Log* _instance;

  Log() = default;
};

Log* Log::_instance = nullptr;

void print_error() { Log::getInstance()->printLog("error"); }

int main() {
  std::thread t1(print_error);
  std::thread t2(print_error);

  t1.join();
  t2.join();

  return 0;
}