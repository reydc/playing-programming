// https://cses.fi/problemset/task/1754
#include <iostream>
#define ll long long
using namespace std;
int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    c = 2*a - b; d = 2*b - a;
    if (c >= 0 && d >= 0 && !(c%3) && !(d%3)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}