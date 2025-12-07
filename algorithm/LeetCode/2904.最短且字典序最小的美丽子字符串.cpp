#include <bits/stdc++.h>

class Solution {
 public:
  std::string shortestBeautifulSubstring(std::string s, int k) {
    if (std::ranges::count(s, '1') < k) {
      return "";
    }

    std::string res = s;
    int l = 0;
    int r = 0;
    int cnt = 0;
    while (r < s.size()) {
      cnt += s[r] - '0';

      while (cnt > k || s[l] == '0') {
        cnt -= s[l] - '0';

        ++l;
      }

      if (cnt == k) {
        std::string temp = s.substr(l, r - l + 1);
        if (temp.size() < res.size() ||
            (temp.size() == res.size() && temp < res)) {
          res = std::move(temp);
        }
      }

      ++r;
    }

    return res;
  }
};