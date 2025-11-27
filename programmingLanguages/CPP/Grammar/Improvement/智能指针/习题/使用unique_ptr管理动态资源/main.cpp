#include <iostream>

#include "ResourceManager.h"

int main() {
  auto myInt = std::make_unique<ResourceManager>(10);
  std::cout << "Initial Value: " << myInt->getValue() << std::endl;
  myInt->setValue(20);
  std::cout << "Update Value: " << myInt->getValue() << std::endl;

  return 0;
}