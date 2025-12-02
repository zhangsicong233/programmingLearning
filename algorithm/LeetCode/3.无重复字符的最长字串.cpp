#include <bits/stdc++.h>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int res = 0;

    int left = 0;
    int right = 0;
    std::unordered_map<char, int> cnt;
    while (right < s.size()) {
      char c = s[right++];
      ++cnt[c];
      while (cnt[c] > 1) {
        --cnt[s[left]];

        left++;
      }

      res = std::max(res, right - left);
    }

    return res;
  }
};