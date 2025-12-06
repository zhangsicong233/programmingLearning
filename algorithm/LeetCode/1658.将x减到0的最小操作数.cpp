#include <bits/stdc++.h>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int x) {
    int res = -1;

    int target = std::reduce(nums.begin(), nums.end()) - x;
    if (target < 0) {
      return -1;
    }

    int l = 0;
    int r = 0;
    int sum = 0;
    while (r < nums.size()) {
      sum += nums[r];

      while (sum > target) {
        sum -= nums[l];
        ++l;
      }

      if (sum == target) {
        res = std::max(res, r - l + 1);
      }

      ++r;
    }

    return res < 0 ? -1 : nums.size() - res;
  }
};