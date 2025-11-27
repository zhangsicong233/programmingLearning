#include <bits/stdc++.h>

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    cpy.push(x);

    while (!mjr.empty()) {
      cpy.push(mjr.front());
      mjr.pop();
    }

    std::swap(mjr, cpy);
  }

  int pop() {
    int res = mjr.front();
    mjr.pop();

    return res;
  }

  int top() { return mjr.front(); }

  bool empty() { return mjr.empty(); }

 private:
  std::queue<int> mjr;
  std::queue<int> cpy;
};
