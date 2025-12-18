#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> getStrongest(std::vector<int>& arr, int k) {
    std::vector<int> res(k);

    std::sort(arr.begin(), arr.end());

    int mid = arr[(arr.size() - 1) / 2];
    int left = 0, right = arr.size() - 1;
    for (int i = 0; i < k; ++i) {
      if (std::abs(arr[left] - mid) > std::abs(arr[right] - mid)) {
        res[i] = arr[left++];
      } else {
        res[i] = arr[right--];
      }
    }

    return res;
  }
};