#include <bits/stdc++.h>

class Solution {
 public:
  int countCompleteSubarrays(std::vector<int>& nums) {
    int res = 0;

    std::unordered_set<int> st(nums.begin(), nums.end());
    std::unordered_map<int, int> cnt;

    int left = 0;
    for (const auto& elem : nums) {
      ++cnt[elem];
      while (cnt.size() == st.size()) {
        --cnt[nums[left]];
        if (!cnt[nums[left]]) {
          cnt.erase(nums[left]);
        }

        ++left;
      }

      res += left;
    }

    return res;
  }
};