// https://cses.fi/problemset/task/1081/
#include <iostream>
#include <algorithm>
using namespace std;
using u = unsigned int;
static int c[1000001];
int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, mx = 1, t;
  cin >> n;
  for (auto i = 0; i < n; i++) {
    cin >> t;
    c[t]++;
    if (mx < t) mx = t;
  }
  t = -1;
  int cc;
  for (auto i = mx; i >= 1; i--) {
    cc = 0;
    for (auto j = i; j <= mx; j += i) {
      if (c[j] >= 2) {
        t = j;
        break;
      }
      if (c[j] == 1) cc++;
      if (cc == 2) {
        t = i;
        break;
      }
    }
    if (t != -1) break;
  }
  cout << t << "\n";
}