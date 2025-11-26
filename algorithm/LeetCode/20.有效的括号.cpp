#include <bits/stdc++.h>

std::unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

class Solution {
 public:
  bool isValid(std::string s) {
    if (s.size() & 1) {
      return false;
    }

    std::stack<char> stk;
    for (const auto& c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else {
        if (stk.empty() || mp[stk.top()] != c) {
          return false;
        }

        stk.pop();
      }
    }

    return stk.empty();
  }
};