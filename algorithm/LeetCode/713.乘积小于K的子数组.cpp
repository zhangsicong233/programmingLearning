#include <bits/stdc++.h>

class Solution {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    int res = 0;

    if (k <= 1) {
      return 0;
    }

    int l = 0;
    int prod = 1;
    for (int r = 0; r < nums.size(); ++r) {
      prod *= nums[r];
      while (prod >= k) {
        prod /= nums[l];

        ++l;
      }

      res += r - l + 1;
    }

    return res;
  }
};