#include <bits/stdc++.h>

class Solution {
 public:
  int totalFruit(std::vector<int>& fruits) {
    int res = 0;

    int l = 0;
    int r = 0;
    std::unordered_map<int, int> cnt;
    while (r < fruits.size()) {
      ++cnt[fruits[r]];

      while (cnt.size() > 2) {
        --cnt[fruits[l]];
        if (!cnt[fruits[l]]) {
          cnt.erase(fruits[l]);
        }

        ++l;
      }

      res = std::max(res, r - l + 1);

      ++r;
    }

    return res;
  }
};
