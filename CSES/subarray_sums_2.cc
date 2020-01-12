// https://cses.fi/problemset/task/1661
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
static int a[200000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x, s, c = 0;
  map<int,int> x_diff;
  cin >> n >> x;
  cin >> a[0];
  s = a[0];
  x_diff[s]++;
  c += s==x;
  for (ll i = 1; i < n; i++) {
    cin >> a[i];
    s += a[i];
    c += s==x;
    if (x_diff.find(s-x) != x_diff.end()) {
      c += x_diff[s-x];
    }
    x_diff[s]++;
  }
  cout << c << "\n";
}