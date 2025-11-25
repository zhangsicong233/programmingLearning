#include <bits/stdc++.h>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int res = 1;
    for (auto i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        nums[res++] = nums[i];
      }
    }

    return res;
  }
};