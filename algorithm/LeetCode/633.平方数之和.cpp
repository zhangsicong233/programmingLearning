#include <bits/stdc++.h>

class Solution {
 public:
  bool judgeSquareSum(int c) {
    int left = 0, right = std::sqrt(c);

    while (left <= right) {
      if (left * left == c - right * right) {
        return true;
      }

      if (left * left < c - right * right) {
        ++left;
      } else {
        --right;
      }
    }

    return false;
  }
};