#include <bits/stdc++.h>

class Solution {
 public:
  long long countSubarrays(std::vector<int>& nums, int k) {
    long long res = 0;

    int max = std::ranges::max(nums);
    int left = 0;
    int cnt = 0;
    for (const auto& elem : nums) {
      if (elem == max) {
        ++cnt;
      }

      while (cnt >= k) {
        if (nums[left++] == max) {
          --cnt;
        }
      }

      res += left;
    }

    return res;
  }
};