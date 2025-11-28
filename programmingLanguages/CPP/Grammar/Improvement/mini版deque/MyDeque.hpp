#pragma once

#include <iostream>

template <typename T>
class MyDeque {
 private:
  T* _buffer;
  std::size_t _capacity;
  std::size_t _count;
  std::size_t _front_idx;
  std::size_t _back_idx;

  class MyIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    MyIterator(MyDeque<T>* deque, std::size_t position)
        : _deque_ptr(deque), _pos(position) {}

    reference operator*() const {
      auto real_idx = (_deque_ptr->_front_idx + _pos) % (_deque_ptr->_capacity);

      return _deque_ptr->_buffer[real_idx];
    }

    pointer operator->() const {
      auto real_idx = (_deque_ptr->_front_idx + _pos) % (_deque_ptr->_capacity);

      return &(_deque_ptr->_buffer[real_idx]);
    }

    MyIterator& operator++() {
      ++_pos;

      return *this;
    }

    MyIterator operator++(int) {
      MyIterator temp = *this;

      ++_pos;

      return temp;
    }

    MyIterator& operator--() {
      --_pos;

      return *this;
    }

    MyIterator operator--(int) {
      MyIterator temp = *this;

      --_pos;

      return temp;
    }

    bool operator==(const MyIterator& other) {
      return (_deque_ptr == other._deque_ptr) && (_pos == other._pos);
    }

    bool operator!=(const MyIterator& other) { return !(*this == other); }

   private:
    MyDeque<T>* _deque_ptr;
    std::size_t _pos;
  };

 public:
  MyDeque(std::size_t initial_capaticy = 10)
      : _capacity(initial_capaticy), _count(0), _front_idx(0), _back_idx(0) {
    _buffer = new T[_capacity]();
  }

  bool empty() { return _count == 0; }

  std::size_t size() { return _count; }

  void resize(std::size_t new_capacity) {
    T* new_buffer = new T[new_capacity]();
    for (auto i = 0; i < _count; ++i) {
      new_buffer[i] = _buffer[(_front_idx + i) % _capacity];
    }

    delete[] _buffer;

    _buffer = new_buffer;
    _front_idx = 0;
    _back_idx = _count;
    _capacity = new_capacity;
  }

  void push_front(const T& value) {
    if (_count == _capacity) {
      resize(_capacity * 2);
    }

    _front_idx = (_front_idx - 1 + _capacity) % _capacity;
    _buffer[_front_idx] = value;

    ++_count;
  }

  void push_back(const T& value) {
    if (_count == _capacity) {
      resize(_capacity * 2);
    }

    _buffer[_back_idx] = value;
    _back_idx = (_back_idx + 1) % _capacity;

    ++_count;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    _front_idx = (_front_idx + 1) % _capacity;
    --_count;
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    _back_idx = (_back_idx - 1 + _capacity) % _capacity;
    --_count;
  }

  T& front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    return _buffer[_front_idx];
  }

  const T& front() const {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    return _buffer[_front_idx];
  }

  T& back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    auto lastIdx = (_back_idx - 1 + _capacity) % _capacity;

    return _buffer[lastIdx];
  }

  const T& back() const {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }

    auto lastIdx = (_back_idx - 1 + _capacity) % _capacity;

    return _buffer[lastIdx];
  }

  MyIterator begin() { return MyIterator(this, 0); }

  MyIterator end() { return MyIterator(this, _count); }

  ~MyDeque() { delete[] _buffer; }
};