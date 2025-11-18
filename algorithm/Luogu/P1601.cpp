#include <bits/stdc++.h>

const int N = 1e5 + 5;
int lenX, lenY, lenRes;
int x[N], y[N], res[N];

void highPrecisionAdd(int* x, int* y, int* res) {
  for (int i = 0; i < lenRes; ++i) {
    res[i] += x[i] + y[i];
    res[i + 1] = res[i] / 10;
    res[i] %= 10;
  }

  if (res[lenRes]) {
    ++lenRes;
  }
}

int main() {
  std::string a, b;
  std::cin >> a >> b;

  lenX = a.size();
  lenY = b.size();
  lenRes = std::max(lenX, lenY);

  for (int i = lenX - 1; i >= 0; --i) {
    x[lenX - 1 - i] = a[i] - '0';
  }

  for (int i = lenY - 1; i >= 0; --i) {
    y[lenY - 1 - i] = b[i] - '0';
  }

  highPrecisionAdd(x, y, res);

  for (int i = lenRes - 1; i >= 0; --i) {
    std::cout << res[i];
  }
  std::cout << '\n';

  return 0;
}