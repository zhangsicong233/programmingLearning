#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int st = std::ranges::lower_bound(nums, target) - nums.begin();
    if (st == nums.size() || nums[st] != target) {
      return {-1, -1};
    }

    int ed = std::ranges::upper_bound(nums, target) - nums.begin() - 1;

    return {st, ed};
  }
};