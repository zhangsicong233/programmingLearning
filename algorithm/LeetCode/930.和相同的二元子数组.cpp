#include <bits/stdc++.h>

class Solution {
 public:
  int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    int res = 0;

    int left1 = 0, left2 = 0;
    int sum1 = 0, sum2 = 0;
    for (int right = 0; right < nums.size(); ++right) {
      sum1 += nums[right];
      while (left1 <= right && sum1 >= goal) {
        sum1 -= nums[left1];

        ++left1;
      }

      sum2 += nums[right];
      while (left2 <= right && sum2 > goal) {
        sum2 -= nums[left2];

        ++left2;
      }

      res += left1 - left2;
    }

    return res;
  }
};