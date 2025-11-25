#include <bits/stdc++.h>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int res = 0;
    for (auto elem : nums) {
      res ^= elem;
    }

    return res;
  }
};