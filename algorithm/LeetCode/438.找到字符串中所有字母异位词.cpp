#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> res;

    std::array<int, 26> target{}, current{};
    for (int i = 0; i < p.size(); ++i) {
      ++target[p[i] - 'a'];
    }

    int right = 0;
    while (right < s.size()) {
      char c = s[right++];
      ++current[c - 'a'];

      int left = right - p.size();
      if (left < 0) {
        continue;
      }

      if (current == target) {
        res.push_back(left);
      }

      --current[s[left] - 'a'];

      ++left;
    }

    return res;
  }
};