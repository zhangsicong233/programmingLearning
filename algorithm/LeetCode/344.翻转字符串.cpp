#include <bits/stdc++.h>

class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    for (int left = 0, right = s.size() - 1; left < right; ++left, --right) {
      std::swap(s[left], s[right]);
    }
  }
};