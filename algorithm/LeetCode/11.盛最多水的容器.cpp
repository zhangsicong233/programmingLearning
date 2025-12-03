#include <bits/stdc++.h>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int res = 0;

    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      int area = (right - left) * std::min(height[left], height[right]);
      res = std::max(res, area);

      height[left] < height[right] ? ++left : --right;
    }

    return res;
  }
};