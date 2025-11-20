#include <bits/stdc++.h>

int l, n, m;
std::vector<int> dist;

bool check(int x) {
  int now = 0;
  int cnt = 0;
  for (int i = 1; i < dist.size(); ++i) {
    if (dist[i] - dist[now] < x) {
      ++cnt;
    } else {
      now = i;
    }
  }

  return cnt <= m;
}

int binarySearchAns() {
  int l = 0;
  int r = 1e9 + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

int main() {
  std::cin >> l >> n >> m;

  dist.push_back(0);
  for (int i = 0; i < n; ++i) {
    int x = -1;
    std::cin >> x;

    dist.push_back(x);
  }
  dist.push_back(l);

  int ans = binarySearchAns();
  std::cout << ans << '\n';

  return 0;
}