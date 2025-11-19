#include <bits/stdc++.h>

bool cmp(const std::vector<int>& x, const std::vector<int>& y) {
  if (x.size() != y.size()) {
    return x.size() > y.size();
  }

  for (int i = x.size() - 1; i >= 0; --i) {
    if (x[i] != y[i]) {
      return x[i] > y[i];
    }
  }

  return true;
}

void highPrecisionSub(std::vector<int>& x, std::vector<int>& y,
                      std::vector<int>& res) {
  int temp = 0;
  for (int i = 0; i < x.size(); ++i) {
    temp = x[i];
    if (i < y.size()) {
      temp -= y[i];
    }

    if (temp < 0) {
      temp += 10;

      --x[i + 1];
    }

    res.push_back(temp);
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

  if (!cmp(x, y)) {
    std::cout << "-";

    std::swap(x, y);
  }

  highPrecisionSub(x, y, res);

  for (int i = res.size() - 1; i >= 0; --i) {
    std::cout << res[i];
  }
  std::cout << '\n';

  return 0;
}