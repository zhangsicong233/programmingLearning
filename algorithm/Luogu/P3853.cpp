#include <bits/stdc++.h>

int l, n, k;
std::vector<int> road;

bool check(int x) {
  int cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    cnt += (road[i + 1] - road[i] - 1) / x;
  }

  return cnt <= k;
}

int binarySearchAns() {
  int l = 0;
  int r = 1e7 + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  return r;
}

int main() {
  std::cin >> l >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x = 0;
    std::cin >> x;

    road.push_back(x);
  }

  int res = binarySearchAns();
  std::cout << res << '\n';

  return 0;
}