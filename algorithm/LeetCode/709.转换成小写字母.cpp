#include <bits/stdc++.h>

class Solution {
 public:
  std::string toLowerCase(std::string s) {
    for (char& ch : s) {
      if (ch >= 65 && ch <= 90) {
        ch |= 32;
      }
    }
    return s;
  }
};
