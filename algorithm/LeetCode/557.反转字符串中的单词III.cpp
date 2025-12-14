#include <bits/stdc++.h>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    int idx = 0;
    while (idx < s.size()) {
      int st = idx;
      while (idx < s.size() && s[idx] != ' ') {
        ++idx;
      }

      int left = st;
      int right = idx - 1;
      while (left < right) {
        std::swap(s[left], s[right]);

        ++left;
        --right;
      }

      ++idx;
    }

    return s;
  }
};