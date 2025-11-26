#include <bits/stdc++.h>

int read4(char* buf);

class Solution {
 public:
  int read(char* buf, int n) {
    int res = 0;
    for (int i = 0; i <= n; ++i) {
      int cur = read4(buf + res);
      if (cur == 0) {
        break;
      }

      res += cur;
    }

    return std::min(res, n);
  }
};