#include "MyList.hpp"

int main() {
  MyList<int> numbers;
  numbers.push_back(100);
  numbers.push_back(200);
  numbers.push_back(300);
  numbers.push_front(50);

  for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  auto iter = numbers.begin();

  ++iter;

  numbers.insert(iter, 150);
  numbers.insert(iter, 200);

  for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  numbers.remove(200);
  for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  auto end_iter = numbers.end();

  --end_iter;
  --end_iter;

  numbers.erase(end_iter);
  for (auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;

  return 0;
}