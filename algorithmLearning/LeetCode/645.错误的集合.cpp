#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::vector<int> ans(2, 0);
    std::vector<int> flag(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      ++flag[nums[i] - 1];
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (flag[i] == 2) {
        ans[0] = i + 1;
      }

      if (flag[i] == 0) {
        ans[1] = i + 1;
      }
    }

    return ans;
  }
};