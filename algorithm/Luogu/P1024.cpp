#include <bits/stdc++.h>

#define int long long

double a, b, c, d;

double func(double x) { return a * x * x * x + b * x * x + c * x + d; }

double binarySearch(double l, double r) {
  while (r - l > 1e-5) {
    double mid = (l + r) / 2;
    if (func(mid) * func(r) < 0) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

void Solution() {
  std::cin >> a >> b >> c >> d;

  for (double x = -100; x < 100; ++x) {
    double y1 = func(x);
    double y2 = func(x + 1);
    if (y1 == 0) {
      std::cout << std::fixed << std::setprecision(2) << x << " ";
    }

    if (y1 * y2 < 0) {
      std::cout << std::fixed << std::setprecision(2) << binarySearch(x, x + 1)
                << " ";
    }
  }
}

signed main() {
  Solution();

  return 0;
}