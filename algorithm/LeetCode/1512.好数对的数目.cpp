#include <bits/stdc++.h>

class Solution {
 public:
  std::unordered_map<int, int> cnt;
  int numIdenticalPairs(std::vector<int>& nums) {
    int res = 0;
    for (const auto& elem : nums) {
      res += cnt[elem];

      ++cnt[elem];
    }

    return res;
  }
};