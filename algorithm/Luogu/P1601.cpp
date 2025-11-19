#include <bits/stdc++.h>

void highPrecisionAdd(const std::vector<int>& x, const std::vector<int>& y,
                      std::vector<int>& res) {
  int temp = 0;
  for (int i = 0; i < x.size() || i < y.size(); ++i) {
    if (i < x.size()) {
      temp += x[i];
    }

    if (i < y.size()) {
      temp += y[i];
    }

    res.push_back(temp % 10);
    temp /= 10;
  }

  if (temp) {
    res.push_back(temp);
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

  highPrecisionAdd(x, y, res);

  for (int i = res.size() - 1; i >= 0; --i) {
    std::cout << res[i];
  }
  std::cout << '\n';

  return 0;
}