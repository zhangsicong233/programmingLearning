#include <bits/stdc++.h>

class Solution {
 public:
  int maxVowels(std::string s, int k) {
    int res = 0;

    int cnt = 0;
    for (int r = 0; r < s.size(); ++r) {
      if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' ||
          s[r] == 'u') {
        ++cnt;
      }

      int l = r - k + 1;
      if (l < 0) {
        continue;
      }

      res = std::max(res, cnt);

      if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' ||
          s[l] == 'u') {
        --cnt;
      }
    }

    return res;
  }
};