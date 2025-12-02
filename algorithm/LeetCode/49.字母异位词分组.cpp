#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> hash;
    for (auto& str : strs) {
      std::string sorted = str;
      std::sort(sorted.begin(), sorted.end());

      hash[sorted].emplace_back(str);
    }

    std::vector<std::vector<std::string>> res;
    for (auto& elem : hash) {
      res.emplace_back(elem.second);
    }

    return res;
  }
};