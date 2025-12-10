#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::vector<int>> reverseSubmatrix(
      std::vector<std::vector<int>>& grid, int x, int y, int k) {
    for (int upRow = x, downRow = x + k - 1; upRow < downRow;
         ++upRow, --downRow) {
      for (int col = y; col < y + k; ++col) {
        std::swap(grid[upRow][col], grid[downRow][col]);
      }
    }

    return grid;
  }
};