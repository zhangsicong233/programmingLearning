#include <bits/stdc++.h>

constexpr int N = 5e3 + 5;

int n, m;
std::array<std::array<int, N>, N> s;

void solution() {
  std::cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    int x, y, v;
    std::cin >> x >> y >> v;

    s[++x][++y] += v;
  }

  for (int i = 1; i <= 5001; ++i) {
    for (int j = 1; j <= 5001; ++j) {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }

  int res = 0;
  for (int i = m; i <= 5001; ++i) {
    for (int j = m; j <= 5001; ++j) {
      res =
          std::max(res, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
    }
  }

  std::cout << res << std::endl;
}

signed main() {
  solution();

  return 0;
}