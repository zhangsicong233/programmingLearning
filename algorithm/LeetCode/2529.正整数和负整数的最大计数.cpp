#include <bits/stdc++.h>

class Solution {
 public:
  int binarySearch(std::vector<int> arr, int target) {
    int l = -1;
    int r = arr.size();

    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (arr[mid] < target) {
        l = mid;
      } else {
        r = mid;
      }
    }

    return l;
  }

  int maximumCount(std::vector<int>& nums) {
    int pos = nums.size() - binarySearch(nums, 1) - 1;
    int neg = binarySearch(nums, 0) + 1;

    return std::max(pos, neg);
  }
};