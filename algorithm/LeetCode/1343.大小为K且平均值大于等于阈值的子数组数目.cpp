#include <bits/stdc++.h>

class Solution {
 public:
  int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    int res = 0;

    double s = 0;
    for (int r = 0; r < arr.size(); ++r) {
      s += arr[r];

      int l = r - k + 1;
      if (l < 0) {
        continue;
      }

      if (s / k >= threshold) {
        ++res;
      }

      s -= arr[l];
    }

    return res;
  }
};