// https://cses.fi/problemset/task/1620
#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int main() {
  ull n, t, x;
  vector<ull> k;
  cin >> n >> t;
  while (n-- && cin >> x) k.emplace_back(x);
  sort(k.begin(), k.end());
  ull l = 1, u = t * k[k.size() - 1], m;
  while (l < u) {
    m = (l + u)>>1;
    ull res = 0;
    for (auto s: k) res += m/s;
    if (res < t) {
      l = m + 1;
    } else {
      u = m;
    }
  }
  cout << l << "\n";
}