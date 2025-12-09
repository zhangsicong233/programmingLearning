#include <bits/stdc++.h>

class Solution {
 public:
  int numberOfSubstrings(std::string s) {
    int res = 0;

    int cnt[3]{};

    int left = 0;
    for (const auto& c : s) {
      ++cnt[c - 'a'];
      while (cnt[0] && cnt[1] && cnt[2]) {
        --cnt[s[left] - 'a'];

        ++left;
      }

      res += left;
    }

    return res;
  }
};