#include <bits/stdc++.h>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int res = std::numeric_limits<int>::max();

    int l = 0;
    int r = 0;
    int sum = 0;
    while (r < nums.size()) {
      sum += nums[r];

      while (sum >= target) {
        res = std::min(res, r - l + 1);

        sum -= nums[l];
        ++l;
      }

      ++r;
    }

    return (res <= nums.size()) ? res : 0;
  }
};