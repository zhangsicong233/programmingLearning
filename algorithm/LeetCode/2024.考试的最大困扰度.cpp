#include <bits/stdc++.h>

class Solution {
 public:
  int maxConsecutiveAnswers(std::string answerKey, int k) {
    int res = 0;

    int l = 0;
    int r = 0;
    std::unordered_map<char, int> cnt;
    while (r < answerKey.size()) {
      ++cnt[answerKey[r]];

      while (cnt['T'] > k && cnt['F'] > k) {
        --cnt[answerKey[l]];

        ++l;
      }

      res = std::max(res, r - l + 1);

      ++r;
    }

    return res;
  }
};