#include <bits/stdc++.h>

#define int long long

const int N = 1e6 + 5;

int n, m;
std::vector<int> arr;

int binarySearch(int target) {
  int l = 0;
  int r = n + 1;

  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (arr[mid] >= target) {
      r = mid;
    } else {
      l = mid;
    }
  }

  if (arr[r] == target) {
    return r;
  } else {
    return -1;
  }
}

void Solution() {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int num;
    std::cin >> num;

    arr.push_back(num);
  }

  for (int i = 0; i < m; ++i) {
    int query;
    std::cin >> query;

    std::cout << binarySearch(query) << " ";
  }
}

signed main() {
  arr.push_back(-1);

  Solution();

  return 0;
}