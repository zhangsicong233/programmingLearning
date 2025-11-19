#include <bits/stdc++.h>

void highPrecisionDiv(const std::vector<int>& x, const int& y,
                      std::vector<int>& res) {
  long long temp = 0;
  for (int i = x.size() - 1; i >= 0; --i) {
    temp = temp * 10 + x[i];
    res.push_back(temp / y);
    temp %= y;
  }

  std::reverse(res.begin(), res.end());

  while (res.size() > 1 && !res.back()) {
    res.pop_back();
  }
}

int main() {
  std::string a;
  int b;
  std::cin >> a >> b;

  std::vector<int> x, res;

  for (int i = a.size() - 1; i >= 0; --i) {
    x.push_back(a[i] - '0');
  }

  highPrecisionDiv(x, b, res);

  for (int i = res.size() - 1; i >= 0; --i) {
    std::cout << res[i];
  }
  std::cout << '\n';

  return 0;
}