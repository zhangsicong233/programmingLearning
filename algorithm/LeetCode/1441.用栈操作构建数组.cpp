#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::string> buildArray(std::vector<int>& target, int n) {
    std::vector<std::string> res;

    for (int i = 1, j = 0; i <= n && j < target.size(); ++i) {
      res.push_back("Push");

      if (i == target[j]) {
        ++j;
      } else {
        res.push_back("Pop");
      }
    }

    return res;
  }
};