#include <bits/stdc++.h>

class Solution {
 public:
  int maximumLengthSubstring(std::string s) {
    int res = 0;

    int l = 0;
    int r = 0;
    std::unordered_map<char, int> cnt;
    while (r < s.size()) {
      ++cnt[s[r]];

      while (cnt[s[r]] > 2) {
        --cnt[s[l]];

        ++l;
      }

      res = std::max(res, r - l + 1);

      ++r;
    }

    return res;
  }
};