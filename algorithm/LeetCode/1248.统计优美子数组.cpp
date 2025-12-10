#include <bits/stdc++.h>

class Solution {
 public:
  int numberOfSubarrays(std::vector<int>& nums, int k) {
    int res = 0;

    int left1 = 0, left2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] & 1) {
        ++cnt1;
        ++cnt2;
      }

      while (left1 <= right && cnt1 >= k) {
        if (nums[left1] & 1) {
          --cnt1;
        }

        ++left1;
      }

      while (left2 <= right && cnt2 > k) {
        if (nums[left2] & 1) {
          --cnt2;
        }

        ++left2;
      }

      res += left1 - left2;
    }

    return res;
  }
};