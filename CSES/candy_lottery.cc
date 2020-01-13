// https://cses.fi/problemset/task/1727
#include <iostream>
#include <iomanip>
using namespace std;

double bin_exp(double b, int e) {
  double res = 1;
  while (e) {
    if (e&1) res = b*res;
    b *= b;
    e >>=1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  double a = 0;
  cin >> n >> k;
  for (auto i = 1; i < k; i++) a += bin_exp(i/static_cast<double>(k), n);
  cout << fixed << setprecision(6) << k-a << "\n";
}