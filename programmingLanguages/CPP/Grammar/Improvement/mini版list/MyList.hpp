#pragma once

#include <iostream>

template <typename T>
struct Node {
  T _data;
  Node* _prev;
  Node* _next;

  Node(const T& value = T()) : _data(value), _prev(nullptr), _next(nullptr) {}
};

template <typename T>
class MyList;

template <typename T>
class MyIterator {
 public:
  using self_type = MyIterator<T>;
  using value_type = T;
  using reference = T&;
  using pointer = T*;
  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;

  MyIterator(Node<T>* ptr = nullptr) : node_ptr(ptr) {}

  reference operator*() const { return node_ptr->_data; }

  pointer operator->() const { return &(node_ptr->_data); }

  self_type& operator++() {
    if (node_ptr) {
      node_ptr = node_ptr->_next;
    }

    return *this;
  }

  self_type operator++(int) {
    self_type temp = *this;

    ++(*this);

    return temp;
  }

  self_type& operator--() {
    if (node_ptr) {
      node_ptr = node_ptr->_prev;
    }

    return *this;
  }

  self_type operator--(int) {
    self_type temp = *this;

    --(*this);

    return temp;
  }

  bool operator==(const self_type& other) const {
    return node_ptr == other.node_ptr;
  }
  bool operator!=(const self_type& other) const { return !(*this == other); }

 private:
  friend class MyList<T>;

  Node<T>* node_ptr;
};

template <typename T>
class MyList {
 public:
  using iterator = MyIterator<T>;
  using const_iterator = MyIterator<T>;

  MyList() {
    dummyHead = new Node<T>();
    dummyTail = new Node<T>();

    dummyHead->_next = dummyTail;
    dummyTail->_prev = dummyHead;
  }

  MyList(const MyList& other) = delete;
  MyList& operator=(const MyList& other) = delete;

  iterator insert(iterator pos, const T& val) {
    Node<T>* newNode = new Node<T>(val);

    Node<T>* currNode = pos.node_ptr;
    Node<T>* prevNode = currNode->_prev;

    newNode->_prev = prevNode;
    currNode->_prev = newNode;

    newNode->_next = currNode;
    prevNode->_next = newNode;

    return iterator(newNode);
  }

  iterator erase(iterator pos) {
    Node<T>* curr = pos.node_ptr;
    if (curr == dummyHead || curr == dummyTail) {
      return iterator(dummyTail);
    }

    Node<T>* prev = curr->_prev;
    Node<T>* next = curr->_next;

    prev->_next = next;
    next->_prev = prev;

    delete curr;

    return iterator(next);
  }

  void remove(const T& value) {
    auto iter = begin();
    while (iter != end()) {
      if (*iter == value) {
        erase(iter);
      } else {
        ++iter;
      }
    }
  }

  iterator begin() { return iterator(dummyHead->_next); }

  iterator end() { return iterator(dummyTail); }

  std::size_t size() {
    auto cnt = 0;
    for (auto iter = begin(); iter != end(); ++iter) {
      ++cnt;
    }

    return cnt;
  }

  bool empty() { return dummyHead->_next == dummyTail; }

  void push_front(const T& value) { insert(begin(), value); }

  void push_back(const T& value) { insert(end(), value); }

  void pop_front() {
    if (!empty()) {
      erase(begin());
    }
  }

  void pop_back() {
    if (!empty()) {
      iterator temp = end();
      --temp;

      erase(temp);
    }
  }

  T& front() { return dummyHead->_next->_data; }

  T& back() { return dummyTail->_prev->_data; }

  void print() const {
    Node<T>* curr = dummyHead->_next;
    while (curr != dummyTail) {
      std::cout << curr->_data;

      curr = curr->_next;
    }
    std::cout << std::endl;
  }

  ~MyList() {
    clear();

    delete dummyHead;
    delete dummyTail;
  }

 private:
  void clear() {
    Node<T>* cur = dummyHead->_next;
    while (cur != dummyTail) {
      Node<T>* temp = cur->_next;
      delete cur;
      cur = temp;
    }

    dummyHead->_next = dummyTail;
    dummyTail->_prev = dummyHead;
  }

  Node<T>* dummyHead;
  Node<T>* dummyTail;
};