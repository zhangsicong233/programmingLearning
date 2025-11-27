#include <bits/stdc++.h>

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { iStk.push(x); }

  int pop() {
    if (oStk.empty()) {
      trans();
    }

    int res = oStk.top();
    oStk.pop();

    return res;
  }

  int peek() {
    if (oStk.empty()) {
      trans();
    }

    return oStk.top();
  }

  bool empty() { return iStk.empty() && oStk.empty(); }

 private:
  void trans() {
    while (!iStk.empty()) {
      oStk.push(iStk.top());
      iStk.pop();
    }
  }

  std::stack<int> iStk;
  std::stack<int> oStk;
};
