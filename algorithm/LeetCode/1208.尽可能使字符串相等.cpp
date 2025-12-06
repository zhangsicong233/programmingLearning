#include <bits/stdc++.h>

class Solution {
 public:
  int equalSubstring(std::string s, std::string t, int maxCost) {
    int res = 0;

    int l = 0;
    int r = 0;
    int sum = 0;
    while (r < s.size()) {
      sum += std::abs(s[r] - t[r]);

      while (sum > maxCost) {
        sum -= std::abs(s[l] - t[l]);
        ++l;
      }

      res = std::max(res, r - l + 1);

      ++r;
    }

    return res;
  }
};