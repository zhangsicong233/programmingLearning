#include <bits/stdc++.h>

class Solution {
 public:
  int vowelStrings(std::vector<std::string>& words, int left, int right) {
    std::set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

    int res = 0;
    for (int i = left; i <= right; ++i) {
      if (vowel.contains(*words[i].begin()) &&
          vowel.contains(*(words[i].end() - 1))) {
        ++res;
      }
    }

    return res;
  }
};