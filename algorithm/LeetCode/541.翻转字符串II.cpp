#include <bits/stdc++.h>

class Solution {
 public:
  std::string reverseStr(std::string s, int k) {
    int n = s.size();

    for (int i = 0; i < s.size(); i += 2 * k) {
      std::reverse(s.begin() + i, s.begin() + std::min(i + k, n));
    }

    return s;
  }
};