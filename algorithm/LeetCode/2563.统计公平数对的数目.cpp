#include <bits/stdc++.h>

class Solution {
 public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    long long res = 0;

    std::ranges::sort(nums);

    for (int idx = 0; idx < nums.size(); ++idx) {
      auto left =
          std::lower_bound(nums.begin(), nums.begin() + idx, lower - nums[idx]);
      auto right =
          std::upper_bound(nums.begin(), nums.begin() + idx, upper - nums[idx]);

      res += right - left;
    }

    return res;
  }
};