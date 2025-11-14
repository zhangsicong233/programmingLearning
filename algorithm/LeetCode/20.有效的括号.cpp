#include <bits/stdc++.h>

class Solution {
 public:
  bool isValid(std::string s) {
    bool flag = true;
    std::stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(')');
      } else if (s[i] == '[') {
        stk.push(']');
      } else if (s[i] == '{') {
        stk.push('}');
      } else {
        if (!stk.empty() && s[i] == stk.top()) {
          stk.pop();
        } else {
          flag = false;
        }
      }
    }

    if (!stk.empty()) {
      flag = false;
    }

    return flag;
  }
};