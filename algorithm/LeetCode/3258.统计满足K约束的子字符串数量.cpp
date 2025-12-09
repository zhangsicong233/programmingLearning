#include <bits/stdc++.h>

class Solution {
 public:
  int countKConstraintSubstrings(std::string s, int k) {
    int res = 0;

    int cnt[2]{};

    int left = 0;
    for (int right = 0; right < s.size(); ++right) {
      ++cnt[s[right] & 1];
      while (cnt[0] > k && cnt[1] > k) {
        --cnt[s[left] & 1];

        ++left;
      }

      res += right - left + 1;
    }

    return res;
  }
};