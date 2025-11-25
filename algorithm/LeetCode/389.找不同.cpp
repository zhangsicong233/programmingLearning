#include <bits/stdc++.h>

class Solution {
 public:
  char findTheDifference(std::string s, std::string t) {
    char res = 0;
    for (auto c : s) {
      res ^= c;
    }

    for (auto c : t) {
      res ^= c;
    }

    return res;
  }
};