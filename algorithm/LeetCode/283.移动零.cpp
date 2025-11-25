#include <bits/stdc++.h>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    int flag = 0;
    for (auto& elem : nums) {
      if (elem) {
        std::swap(elem, nums[flag]);

        ++flag;
      }
    }
  }
};