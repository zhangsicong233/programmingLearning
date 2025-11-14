#include <bits/stdc++.h>

class Solution {
 public:
  std::string pathEncryption(std::string path) {
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '.') {
        path[i] = ' ';
      }
    }

    return path;
  }
};