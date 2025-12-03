#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;

    std::ranges::sort(nums);

    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
      int cur = nums[i];
      if (i && cur == nums[i - 1]) {
        continue;
      }

      if (cur + nums[n - 2] + nums[n - 1] < 0) {
        continue;
      }

      if (cur + nums[i + 1] + nums[i + 2] > 0) {
        break;
      }

      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int s = cur + nums[left] + nums[right];
        if (s < 0) {
          ++left;
        } else if (s > 0) {
          --right;
        } else {
          res.push_back({cur, nums[left], nums[right]});

          ++left;
          --right;

          while (left < right && nums[left] == nums[left - 1]) {
            ++left;
          }

          while (left < right && nums[right] == nums[right + 1]) {
            --right;
          }
        }
      }
    }

    return res;
  }
};