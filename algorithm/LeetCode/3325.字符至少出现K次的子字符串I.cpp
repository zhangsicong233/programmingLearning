#include <bits/stdc++.h>

class Solution {
 public:
  int numberOfSubstrings(std::string s, int k) {
    int res = 0;

    int cnt[26]{};

    int left = 0;
    for (const auto& c : s) {
      ++cnt[c - 'a'];
      while (cnt[c - 'a'] >= k) {
        --cnt[s[left] - 'a'];

        ++left;
      }

      res += left;
    }

    return res;
  }
};