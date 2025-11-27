#include "ResourceManager.h"

ResourceManager::ResourceManager() : _data(nullptr) {}

ResourceManager::ResourceManager(int val) : _data(std::make_unique<int>(val)) {}

ResourceManager::ResourceManager(ResourceManager&& other) noexcept {
  *this = std::move(other);
}

ResourceManager& ResourceManager::operator=(ResourceManager&& other) noexcept {
  if (this != &other) {
    *this = std::move(other);
  }

  return *this;
}

void ResourceManager::setValue(int newValue) { *_data = newValue; }

int ResourceManager::getValue() const { return *_data; }