#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<double> convertTemperature(double celsius) {
    std::vector<double> res;
    double kel = celsius + 273.15;
    res.push_back(kel);

    double fah = celsius * 1.8 + 32;
    res.push_back(fah);

    return res;
  }
};