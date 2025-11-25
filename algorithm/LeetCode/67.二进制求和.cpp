#include <bits/stdc++.h>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int temp = 0;
    std::string res;
    int n = std::max(a.size(), b.size());
    for (int i = 0; i < n; ++i) {
      if (i < a.size()) {
        temp += (a[i] - '0');
      }

      if (i < b.size()) {
        temp += (b[i] - '0');
      }

      res.push_back((temp % 2) ? '1' : '0');
      temp /= 2;
    }

    if (temp) {
      res.push_back('1');
    }

    std::reverse(res.begin(), res.end());

    return res;
  }
};