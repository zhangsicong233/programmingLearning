#include <bits/stdc++.h>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    int res = 0;
    std::unordered_set<int> st(nums.begin(), nums.end());
    for (auto& i : st) {
      if (st.contains(i - 1)) {
        continue;
      }

      int j = i + 1;
      while (st.contains(j)) {
        ++j;
      }

      res = std::max(res, j - i);
    }

    return res;
  }
};