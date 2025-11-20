#include <bits/stdc++.h>

typedef long long ll;

int n, k;
std::vector<int> arr;

bool check(int x) {
  ll y = 0;
  for (int i = 0; i <= n; ++i) {
    y += arr[i] / x;
  }

  return y >= k;
}

int binarySearchAnswer() {
  int l = 0;
  int r = 1e8 + 5;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

int main() {
  std::cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int temp = -1;
    std::cin >> temp;

    arr.push_back(temp);
  }

  int ans = binarySearchAnswer();

  std::cout << ans << '\n';

  return 0;
}