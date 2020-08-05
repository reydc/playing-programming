// https://cses.fi/problemset/task/1661
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
  x_diff[0] = 1;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    if (x_diff.find(s-x) != x_diff.end()) {
      c += x_diff[s-x];
    }
    x_diff[s]++;
  }
  cout << c << "\n";
}