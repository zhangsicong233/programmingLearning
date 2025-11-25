#include <bits/stdc++.h>

class Solution {
 public:
  int lengthOfLastWord(std::string s) {
    int l = s.length() - 1;
    while (s[l] == ' ') {
      --l;
    }

    int r = l - 1;
    while (r >= 0 && s[r] != ' ') {
      --r;
    }

    return l - r;
  }
};