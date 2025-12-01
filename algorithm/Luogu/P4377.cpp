#include <bits/stdc++.h>

int n, W;
std::array<int, 255> w, t;
std::array<double, 1005> f;

bool check(double x) {
  for (int i = 1; i <= W; ++i) {
    f[i] = -1e9;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = W; j >= 0; --j) {
      int k = std::min(W, j + w[i]);
      f[k] = std::max(f[k], f[j] + t[i] - x * w[i]);
    }
  }

  return f[W] >= 0;
}

double binarySearchAns() {
  double l = 0;
  double r = 1e3 + 1e-9;
  while (r - l > 1e-6) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

void solution() {
  std::cin >> n >> W;

  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i] >> t[i];
  }

  int res = std::floor(1000 * binarySearchAns());
  std::cout << res << std::endl;
}

int main() {
  solution();

  return 0;
}