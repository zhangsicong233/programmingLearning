#include <bits/stdc++.h>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int ans = -1;
    int cnt = 0;
    for (int i : nums) {
      if (i) {
        ++cnt;
      } else {
        ans = std::max(ans, cnt);

        cnt = 0;
      }
    }

    ans = std::max(ans, cnt);

    return ans;
  }
};