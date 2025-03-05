#include <bits/stdc++.h>

class Solution {
 public:
  std::string dynamicPassword(std::string password, int target) {
    std::string ans = password.substr(target, password.size() - target) +
                      password.substr(0, target);

    return ans;
  }
};