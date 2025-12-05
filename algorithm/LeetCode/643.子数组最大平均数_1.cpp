#include <bits/stdc++.h>

class Solution {
 public:
  double findMaxAverage(std::vector<int>& nums, int k) {
    double res = std::numeric_limits<int>::min();

    double s = 0;
    for (int r = 0; r < nums.size(); ++r) {
      s += nums[r];

      int l = r - k + 1;
      if (l < 0) {
        continue;
      }

      res = std::max(res, s / k);

      s -= nums[l];
    }

    return res;
  }
};