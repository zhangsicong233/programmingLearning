#include <bits/stdc++.h>

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string res = strs[0];
    for (int i = 0; i < res.size(); ++i) {
      for (auto s : strs) {
        if (i == s.size() || s[i] != res[i]) {
          return res.substr(0, i);
        }
      }
    }

    return res;
  }
};