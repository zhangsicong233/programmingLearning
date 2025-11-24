#include <bits/stdc++.h>

std::unordered_map<char, int> ROMAN{{'I', 1},   {'V', 5},   {'X', 10},
                                    {'L', 50},  {'C', 100}, {'D', 500},
                                    {'M', 1000}};

class Solution {
 public:
  int romanToInt(std::string s) {
    int res = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
      int x = ROMAN[s[i]];
      int y = ROMAN[s[i + 1]];
      res += x < y ? -x : x;
    }

    return res + ROMAN[s.back()];
  }
};