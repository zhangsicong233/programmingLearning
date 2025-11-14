#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::vector<int> ans;

    int n = nums.size();
    for (auto& num : nums) {
      int idx = (num - 1) % n;
      if (nums[idx] <= n) {
        nums[idx] += n;
      }
    }

    for (int i = 0; i < n; ++i) {
      std::cout << nums[i] << "***";
      if (nums[i] <= n) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};
