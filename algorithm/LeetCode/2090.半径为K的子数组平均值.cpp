#include <bits/stdc++.h>

using ll = long long;

class Solution {
 public:
  std::vector<int> getAverages(std::vector<int>& nums, int k) {
    std::vector<int> res(nums.size(), -1);

    ll s = 0;
    for (int r = 0; r < nums.size(); ++r) {
      s += nums[r];

      int l = r + 1 - (2 * k + 1);
      if (l < 0) {
        continue;
      }

      res[l + k] = s / (2 * k + 1);

      s -= nums[l];
    }

    return res;
  }
};