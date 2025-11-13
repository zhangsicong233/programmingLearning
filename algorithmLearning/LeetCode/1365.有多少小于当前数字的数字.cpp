#include <bits/stdc++.h>

using pii = std::pair<int, int>;

class Solution {
 public:
  std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    std::vector<int> copy = nums;

    std::sort(copy.begin(), copy.end());

    int n = nums.size();
    int hash[101];
    for (int i = n - 1; i >= 0; --i) {
      hash[copy[i]] = i;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      ans.push_back(hash[nums[i]]);
    }

    return ans;
  }
};