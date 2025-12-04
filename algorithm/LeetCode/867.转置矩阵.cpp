#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::vector<int>> transpose(
      std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> res(m, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res[j][i] = matrix[i][j];
      }
    }

    return res;
  }
};