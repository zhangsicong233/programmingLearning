#include <bits/stdc++.h>

constexpr int N = 1e5 + 5;

int n, m, l, r;
std::array<int, N> a, s;

void solution() {
  std::cin >> n;

  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];

    s[i] = s[i - 1] + a[i];
  }

  std::cin >> m;

  for (int i = 0; i < m; ++i) {
    std::cin >> l >> r;

    std::cout << s[r] - s[l - 1] << std::endl;
  }
}

signed main() {
  solution();

  return 0;
}