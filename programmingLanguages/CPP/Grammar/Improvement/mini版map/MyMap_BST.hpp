#pragma once

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename Key, typename T>
struct TreeNode {
  std::pair<Key, T> _data;
  TreeNode* _parent;
  TreeNode* _left;
  TreeNode* _right;

  TreeNode(const Key& key, const T& value, TreeNode* parentNode = nullptr)
      : _data(std::make_pair(key, value)),
        _parent(parentNode),
        _left(nullptr),
        _right(nullptr) {}
};

template <typename Key, typename T>
class BSTMap {
 private:
  TreeNode<Key, T>* _root;

  TreeNode<Key, T>* minimum(TreeNode<Key, T>* node) const {
    while (node->_left) {
      node = node->_left;
    }

    return node;
  }

  TreeNode<Key, T>* maximum(TreeNode<Key, T>* node) const {
    while (node->_right) {
      node = node->_right;
    }

    return node;
  }

  void clear(TreeNode<Key, T>* node) {
    if (!node) {
      return;
    }

    clear(node->_left);
    clear(node->_right);

    delete node;
  }

  class MyIterator {
   private:
    TreeNode<Key, T>* _current;

    TreeNode<Key, T>* minimum(TreeNode<Key, T>* node) const {
      while (node && node->_left) {
        node = node->_left;
      }

      return node;
    }

    TreeNode<Key, T>* maximum(TreeNode<Key, T>* node) const {
      while (node && node->_right) {
        node = node->_right;
      }

      return node;
    }

    TreeNode<Key, T>* successor(TreeNode<Key, T>* node) const {
      if (!node) {
        return nullptr;
      }

      if (node->_right) {
        return minimum(node->_right);
      }

      TreeNode<Key, T>* p = node->_parent;
      while (p && node == p->_right) {
        node = p;

        p = p->_parent;
      }

      return p;
    }

   public:
    MyIterator(TreeNode<Key, T>* node = nullptr) : _current(node) {}

    std::pair<Key, T>& operator*() {
      if (!_current) {
        throw std::out_of_range("");
      }

      return _current->_data;
    }

    std::pair<Key, T>* operator->() {
      if (!_current) {
        throw std::out_of_range("");
      }

      return &(_current->_data);
    }

    // 前置递增
    MyIterator& operator++() {
      _current = successor(_current);

      return *this;
    }

    // 后置递增
    MyIterator operator++(int) {
      MyIterator temp = *this;
      _current = successor(_current);

      return temp;
    }

    bool operator==(const MyIterator& other) const {
      return _current == other._current;
    }

    bool operator!=(const MyIterator& other) const {
      return _current != other._current;
    }
  };

 public:
  BSTMap() : _root(nullptr) {}

  BSTMap(const BSTMap&) = delete;
  BSTMap& operator=(const BSTMap&) = delete;

  TreeNode<Key, T>* find(const Key& key) const {
    auto* curr = _root;
    while (curr) {
      if (key < curr->_data.first) {
        curr = curr->_left;
      } else if (key > curr->_data.first) {
        curr = curr->_right;
      } else {
        return curr;
      }
    }

    return nullptr;
  }

  void insert(const Key& key, const T& value) {
    if (!_root) {
      _root = new TreeNode<Key, T>(key, value);

      return;
    }

    TreeNode<Key, T>* curr = _root;
    TreeNode<Key, T>* prnt = nullptr;

    while (curr) {
      prnt = curr;
      if (key < curr->_data.first) {
        curr = curr->_left;
      } else if (key > curr->_data.first) {
        curr = curr->_right;
      } else {
        curr->_data.second = value;

        return;
      }
    }

    if (key < prnt->_data.first) {
      prnt->_left = new TreeNode<Key, T>(key, value, prnt);
    } else {
      prnt->_right = new TreeNode<Key, T>(key, value, prnt);
    }
  }

  void erase(const Key& key) {
    auto* deleteNode = find(key);
    if (!deleteNode) {
      return;
    }

    if (deleteNode->_left && deleteNode->_right) {
      auto* successor = minimum(deleteNode->_right);

      deleteNode->_data = successor->_data;
      deleteNode = successor;
    }

    auto* children =
        (deleteNode->_left) ? deleteNode->_left : deleteNode->_right;
    if (children) {
      children->_parent = deleteNode->_parent;
    }

    if (!deleteNode->_parent) {
      _root = children;
    } else if (deleteNode == deleteNode->_parent->_left) {
      deleteNode->_parent->_left = children;
    } else {
      deleteNode->_parent->_right = children;
    }

    delete deleteNode;
  }

  MyIterator begin() const { return MyIterator(minimum(_root)); }

  MyIterator end() const { return MyIterator(nullptr); }

  void clear() {
    clear(_root);

    _root = nullptr;
  }

  ~BSTMap() { clear(_root); }
};
