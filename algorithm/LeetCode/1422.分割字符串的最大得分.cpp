#include <bits/stdc++.h>

class Solution {
 public:
  int maxScore(std::string s) {
    int res = 0;
    int score = std::ranges::count(s, '1');
    for (int i = 0; i + 1 < s.size(); ++i) {
      score += s[i] == '0' ? 1 : -1;

      res = std::max(res, score);
    }

    return res;
  }
};