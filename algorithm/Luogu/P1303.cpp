#include <bits/stdc++.h>

void highPrecisionMul(std::vector<int>& x, std::vector<int>& y,
                      std::vector<int>& res) {
  for (int i = 0; i < x.size(); ++i) {
    for (int j = 0; j < y.size(); ++j) {
      res[i + j] += x[i] * y[j];
      res[i + j + 1] += res[i + j] / 10;
      res[i + j] %= 10;
    }
  }

  while (res.size() > 1 && !res.back()) {
    res.pop_back();
  }
}

int main() {
  std::string a, b;
  std::cin >> a >> b;

  std::vector<int> x, y, res;

  for (int i = a.size() - 1; i >= 0; --i) {
    x.push_back(a[i] - '0');
  }

  for (int i = b.size() - 1; i >= 0; --i) {
    y.push_back(b[i] - '0');
  }

  res.resize(x.size() + y.size(), 0);
  highPrecisionMul(x, y, res);

  for (int i = res.size() - 1; i >= 0; --i) {
    std::cout << res[i];
  }
  std::cout << '\n';
}