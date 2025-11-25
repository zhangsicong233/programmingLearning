#include <bits/stdc++.h>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int stkSize = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[stkSize++] = nums[i];
      }
    }

    return stkSize;
  }
};