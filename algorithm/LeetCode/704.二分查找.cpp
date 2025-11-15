#include <bits/stdc++.h>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    int l = -1;
    int r = nums.size();

    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (nums[mid] <= target) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (l != -1 && nums[l] == target) {
      return l;
    } else {
      return -1;
    }
  }
};