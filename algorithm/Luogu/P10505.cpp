#include <bits/stdc++.h>

constexpr int N = 1e3 + 5;

int n, k;
std::array<double, N> a, b, c;

bool check(double x) {
  for (int i = 0; i < n; ++i) {
    c[i] = a[i] - x * b[i];
  }

  std::sort(c.begin(), c.begin() + n);

  double s = 0;
  for (int i = k; i < n; ++i) {
    s += c[i];
  }

  return s >= 0;
}

double binarySearchAns() {
  double l = 0;
  double r = 1;
  while (r - l > 1e-5) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return r;
}

void solution() {
  while ((std::cin >> n >> k), n) {
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }

    int res = std::round(100 * binarySearchAns());
    std::cout << res << std::endl;
  }
}

int main() {
  solution();

  return 0;
}