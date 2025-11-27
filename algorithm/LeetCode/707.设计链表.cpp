class MyLinkedList {
 public:
  struct LinkedNode {
    int _val;
    LinkedNode* _next;

    LinkedNode(int val) : _val(val), _next(nullptr) {}
  };

  MyLinkedList() {
    _size = 0;
    _dummyHead = new LinkedNode(-1);
  }

  int get(int index) {
    if (index < 0 || index >= _size) {
      return -1;
    }

    auto cur = _dummyHead->_next;
    while (index--) {
      cur = cur->_next;
    }

    return cur->_val;
  }

  void addAtHead(int val) {
    LinkedNode* newNode = new LinkedNode(val);

    newNode->_next = _dummyHead->_next;
    _dummyHead->_next = newNode;

    ++_size;
  }

  void addAtTail(int val) {
    LinkedNode* newNode = new LinkedNode(val);

    auto prev = _dummyHead;
    while (prev->_next) {
      prev = prev->_next;
    }

    prev->_next = newNode;

    ++_size;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > _size) {
      return;
    }

    LinkedNode* newNode = new LinkedNode(val);

    auto prev = _dummyHead;
    while (index--) {
      prev = prev->_next;
    }

    newNode->_next = prev->_next;
    prev->_next = newNode;

    ++_size;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= _size) {
      return;
    }

    auto prev = _dummyHead;
    while (index--) {
      prev = prev->_next;
    }

    auto tmp = prev->_next;
    prev->_next = prev->_next->_next;

    --_size;

    delete tmp;
  }

 private:
  int _size;
  LinkedNode* _dummyHead;
};
