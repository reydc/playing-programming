// https://cses.fi/problemset/task/1660
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
static ll a[200000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x, s = 0, c = 0;
  map<ll,ll> x_diff;
  cin >> n >> x;
  for (auto i = 0; i < n; i++) cin >> a[i];
  for (auto i = 0; i < n; i++) {
    s += a[i];
    if (s > x && x_diff.find(s - x) != x_diff.end()) {
      c += x_diff[s - x];
    }
    if (s == x) c++;
    x_diff[s]++;
  }
  cout << c << "\n";
}