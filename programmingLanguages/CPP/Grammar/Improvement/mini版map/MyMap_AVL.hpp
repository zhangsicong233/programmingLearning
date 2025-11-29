#pragma once

#include <functional>
#include <iostream>
#include <utility>
#include <vector>

template <typename Key, typename Val>
struct AVLNode {
  Key _key;
  Val _value;

  int _height;
  AVLNode* _left;
  AVLNode* _right;

  AVLNode(const Key key, const Val value)
      : _key(key), _value(value), _height(1), _left(nullptr), _right(nullptr) {}
};

template <typename Key, typename Val>
class AVLMap {
 private:
  AVLNode<Key, Val>* _root;

  int getHeight(AVLNode<Key, Val>* node) {
    if (!node) {
      return 0;
    }

    return node->_height;
  }

  int getBalance(AVLNode<Key, Val>* node) {
    if (!node) {
      return 0;
    }

    return getHeight(node->_left) - getHeight(node->_right);
  }

  AVLNode<Key, Val>* rightRotate(AVLNode<Key, Val>* node) {
    auto* x = node->_left;
    auto* rT = x->_right;

    x->_right = node;
    node->_left = rT;

    node->_height = std::max(getHeight(node->_left), getHeight(node->_right));
    x->_height = std::max(getHeight(x->_left), getHeight(x->_right));

    return x;
  }

  AVLNode<Key, Val>* leftRotate(AVLNode<Key, Val>* node) {
    auto* y = node->_right;
    auto* lT = y->_left;

    y->_left = node;
    node->_right = lT;

    node->_height = std::max(getHeight(node->_left), getHeight(node->_right));
    y->_height = std::max(getHeight(y->_left), getHeight(y->_right));

    return y;
  }

  AVLNode<Key, Val>* getMinNode(AVLNode<Key, Val>* node) {
    auto curr = node;
    while (curr->_left) {
      curr = curr->_left;
    }

    return curr;
  }

  AVLNode<Key, Val>* insertNode(AVLNode<Key, Val>* node, const Key& key,
                                const Val& value) {
    if (!node) {
      return new AVLNode<Key, Val>(key, value);
    }

    if (key < node->_key) {
      node->_left = insertNode(node->_left, key, value);
    } else if (key > node->_key) {
      node->_right = insertNode(node->_right, key, value);
    } else {
      node->_value = value;

      return node;
    }

    node->_height =
        std::max(getHeight(node->_left), getHeight(node->_right)) + 1;

    int balance = getBalance(node);
    // LL
    if (balance > 1 && key < node->_left->_key) {
      return rightRotate(node);
    }

    // RR
    if (balance < -1 && key > node->_right->_key) {
      return leftRotate(node);
    }

    // LR
    if (balance > 1 && key > node->_left->_key) {
      node->_left = leftRotate(node->_left);

      return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->_right->_key) {
      node->_right = rightRotate(node->_right);

      return leftRotate(node);
    }

    return node;
  }

  AVLNode<Key, Val>* deleteNode(AVLNode<Key, Val>* node, const Key& key) {
    if (!node) {
      return node;
    }

    if (key < node->_key) {
      node->_left = deleteNode(node->_left, key);
    } else if (key > node->_key) {
      node->_right = deleteNode(node->_right, key);
    } else {
      if (!(node->_left) || !(node->_right)) {
        auto* temp = (node->_left) ? node->_left : node->_right;
        if (!temp) {
          temp = node;

          node = nullptr;
        } else {
          *node = *temp;
        }

        delete temp;
      } else {
        auto* temp = getMinNode(node->_right);
        node->_key = temp->_key;
        node->_value = temp->_value;

        node->_right = deleteNode(node->_right, temp->_key);
      }
    }

    if (!node) {
      return node;
    }

    node->_height =
        std::max(getHeight(node->_left), getHeight(node->_right)) + 1;

    int balance = getBalance(node);
    if (balance > 1 && key < node->_left->_key) {
      return rightRotate(node);
    }

    // RR
    if (balance < -1 && key > node->_right->_key) {
      return leftRotate(node);
    }

    // LR
    if (balance > 1 && key > node->_left->_key) {
      node->_left = leftRotate(node->_left);

      return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->_right->_key) {
      node->_right = rightRotate(node->_right);

      return leftRotate(node);
    }

    return node;
  }

  Val* searchNode(AVLNode<Key, Val>* node, const Key& key) {
    if (!node) {
      return nullptr;
    }

    if (key < node->_key) {
      return searchNode(node->_left, key);
    } else if (key > node->_key) {
      return searchNode(node->_right, key);
    } else {
      return &(node->_value);
    }
  }

  void inorderHelper(AVLNode<Key, Val>* node,
                     std::vector<std::pair<Key, Val>>& result) const {
    if (!node) {
      return;
    }

    inorderHelper(node->_left, result);

    result.emplace_back(std::make_pair(node->_key, node->_value));

    inorderHelper(node->_right, result);
  }

 public:
  AVLMap() : _root(nullptr) {}

  void put(const Key& key, const Val& value) {
    _root = insertNode(_root, key, value);
  }

  Val* get(const Key& key) { return searchNode(_root, key); }

  void remove(const Key& key) { _root = deleteNode(_root, key); }

  std::vector<std::pair<Key, Val>> inorderTraversal() const {
    std::vector<std::pair<Key, Val>> result;
    inorderHelper(_root, result);

    return result;
  }

  ~AVLMap() {
    std::function<void(AVLNode<Key, Val>*)> destroy =
        [&](AVLNode<Key, Val>* node) {
          if (node) {
            destroy(node->_left);
            destroy(node->_right);

            delete node;
          }
        };

    destroy(_root);
  }
};