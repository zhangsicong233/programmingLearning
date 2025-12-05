#include <bits/stdc++.h>

using ll = long long;

class Solution {
 public:
  int maxScore(std::vector<int>& cardPoints, int k) {
    int res = 0;

    int s = 0;
    int len = cardPoints.size();
    for (int r = -k; r < k; ++r) {
      s += cardPoints[(r + len) % len];

      int l = r - k + 1;
      if (l < -k) {
        continue;
      }

      res = std::max(res, s);

      s -= cardPoints[(l + len) % len];
    }

    return res;
  }
};