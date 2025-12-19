#include <bits/stdc++.h>

class Solution {
 public:
  int triangleNumber(std::vector<int>& nums) {
    int res = 0;

    std::ranges::sort(nums);

    int n = nums.size();
    for (int idx = 0; idx < n - 2; ++idx) {
      int a = nums[idx];
      if (a == 0) {
        continue;
      }

      int left = idx + 1;
      for (int right = idx + 2; right < n; ++right) {
        while (nums[right] - nums[left] >= a) {
          ++left;
        }

        res += right - left;
      }
    }

    return res;
  }
};