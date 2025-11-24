#include <bits/stdc++.h>

#include <map>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = hashMap.find(target - nums[i]);
      if (it != hashMap.end()) {
        return {i, it->second};
      }

      hashMap[nums[i]] = i;
    }

    return {};
  }
};