#pragma once

#include <memory>

class ResourceManager {
 private:
  std::unique_ptr<int> _data;

 public:
  ResourceManager();
  explicit ResourceManager(int val);
  ResourceManager(ResourceManager&& other) noexcept;
  ResourceManager& operator=(ResourceManager&& other) noexcept;

  ResourceManager(const ResourceManager& other) = delete;
  ResourceManager& operator=(const ResourceManager& other) = delete;

  void setValue(int newValue);
  int getValue() const;
};