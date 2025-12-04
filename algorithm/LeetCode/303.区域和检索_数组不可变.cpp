#include <bits/stdc++.h>

class NumArray {
 public:
  NumArray(std::vector<int>& nums) {
    nums.insert(nums.begin(), 0);

    prefixSum.resize(nums.size());
    for (int i = 1; i < nums.size(); ++i) {
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefixSum[right + 1] - prefixSum[left];
  }

 private:
  std::vector<int> prefixSum;
};
