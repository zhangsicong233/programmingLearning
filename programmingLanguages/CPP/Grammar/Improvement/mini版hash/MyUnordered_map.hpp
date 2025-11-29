#pragma once

#include <functional>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename Key, typename T>
struct HashNode {
  std::pair<const Key, T> _data;
  HashNode* _next;

  HashNode(const Key& key, const T& value)
      : _data(std::make_pair(key, value)), _next(nullptr) {}
};

template <typename Key, typename T, typename Hash = std::hash<Key>>
class MyUnordered_map {
 public:
  class MyIterator;

  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using size_type = std::size_t;

  MyUnordered_map(size_type init_capacity = 16, double max_loda_factor = 0.75)
      : _bucket_count(init_capacity),
        _element_count(0),
        _max_load_factor(max_loda_factor),
        _hash_func(Hash()) {
    _buckets.resize(_bucket_count, nullptr);
  }

  MyUnordered_map(const MyUnordered_map& other) = delete;
  MyUnordered_map& operator=(const MyUnordered_map& other) = delete;

  void insert(const Key& key, const T& value) {
    size_type hash_val = _hash_func(key);
    size_type idx = hash_val % _bucket_count;

    auto* node = _buckets[idx];
    while (node) {
      if (node->_data.first == key) {
        node->_data.second = value;

        return;
      }

      node = node->_next;
    }

    auto* new_node = new HashNode<Key, T>(key, value);
    new_node->_next = _buckets[idx];
    _buckets[idx] = new_node;

    ++_element_count;

    auto load_factor = static_cast<double>(_element_count) / _bucket_count;
    if (load_factor > _max_load_factor) {
      rehash();
    }
  }

  T* find(const Key& key) {
    size_type hash_idx = _hash_func(key) % _bucket_count;
    auto* node = _buckets[hash_idx];
    while (node) {
      if (node->_data.first == key) {
        return &(node->_data.second);
      }

      node = node->_next;
    }

    return nullptr;
  }

  bool erase(const Key& key) {
    auto hash_idx = _hash_func(key) % _bucket_count;
    auto* node = _buckets[hash_idx];
    HashNode<Key, T>* prev = nullptr;
    while (node) {
      if (node->_data.first == key) {
        if (!prev) {
          _buckets[hash_idx] = node->_next;
        } else {
          prev->_next = node->_next;
        }

        delete node;

        --_element_count;

        return true;
      }

      prev = node;
      node = node->_next;
    }

    return false;
  }

  size_type size() const { return _element_count; }

  bool empty() const { return _element_count == 0; }

  void clear() {
    for (size_type i = 0; i < _buckets.size(); ++i) {
      HashNode<Key, T>* current_node = _buckets[i];
      while (current_node) {
        auto* temp = current_node;
        current_node = current_node->_next;

        delete temp;
      }

      _buckets[i] = nullptr;
    }

    _element_count = 0;
  }

  MyIterator begin() {
    for (size_type i = 0; i < _bucket_count; ++i) {
      if (_buckets[i]) {
        return MyIterator(this, i, _buckets[i]);
      }
    }

    return end();
  }

  MyIterator end() { return MyIterator(this, _bucket_count, nullptr); }

  ~MyUnordered_map() { clear(); }

  class MyIterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::pair<const Key, T>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    MyIterator(MyUnordered_map* map, size_type bucket_idx,
               HashNode<Key, T>* node)
        : _map(map), _bucket_idx(bucket_idx), _current_node(node) {}

    reference operator*() const {
      if (!_current_node) {
        throw std::out_of_range("Iterator out of range");
      }

      return _current_node->_data;
    }

    pointer operator->() const {
      if (!_current_node) {
        throw std::out_of_range("Iterator out of range");
      }

      return &(_current_node->_data);
    }

    MyIterator& operator++() {
      advance();

      return *this;
    }

    MyIterator operator--() {
      auto* temp = *this;
      advance();

      return temp;
    }

    bool operator==(const MyIterator& other) const {
      return _map == other._map && _bucket_idx == other._bucket_idx &&
             _current_node == other._current_node;
    }

    bool operator!=(const MyIterator& other) const { return !(*this == other); }

   private:
    MyUnordered_map* _map;
    size_type _bucket_idx;
    HashNode<Key, T>* _current_node;

    void advance() {
      if (_current_node) {
        _current_node = _current_node->_next;
      }

      while (!_current_node) {
        ++_bucket_idx;
        if (_bucket_idx < _map->_bucket_count) {
          _current_node = _map->_buckets[_bucket_idx];
        } else {
          break;
        }
      }
    }
  };

 private:
  std::vector<HashNode<Key, T>*> _buckets;
  size_type _bucket_count;
  size_type _element_count;
  double _max_load_factor;
  Hash _hash_func;

  void rehash() {
    auto new_bucket_count = _bucket_count * 2;
    std::vector<HashNode<Key, T>*> new_buckets(new_bucket_count, nullptr);
    for (size_type i = 0; i < _buckets.size(); ++i) {
      auto* node = _buckets[i];
      while (node) {
        auto* next_node = node->_next;
        auto new_idx = _hash_func(node->_data.first) % new_bucket_count;

        node->_next = new_buckets[new_idx];
        new_buckets[new_idx] = node;

        node = next_node;
      }
    }

    _buckets = std::move(new_buckets);
    _bucket_count = new_bucket_count;
  }
};