#include <bits/stdc++.h>

class Solution {
 public:
  int balancedString(std::string s) {
    int res = s.size();

    std::unordered_map<char, int> cnt;
    for (const auto& c : s) {
      ++cnt[c];
    }

    int target = s.size() / 4;
    if (cnt['Q'] == target && cnt['W'] == target && cnt['E'] == target &&
        cnt['R'] == target) {
      return 0;
    }

    int l = 0;
    for (int r = 0; r < s.size(); ++r) {
      --cnt[s[r]];
      while (cnt['Q'] <= target && cnt['W'] <= target && cnt['E'] <= target &&
             cnt['R'] <= target) {
        res = std::min(res, r - l + 1);

        ++cnt[s[l]];
        ++l;
      }
    }

    return res;
  }
};