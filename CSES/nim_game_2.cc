// https://cses.fi/problemset/task/1098
#include <iostream>
using namespace std;
using ll = long long;
static ll test[200000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t, n, x;
  cin >> t;
  for (auto i = 0; i < t; i++) {
    cin >> n;
    for (auto j = 0; j < n; j++) {
      cin >> x;
      test[i] ^= (x%4);
    }
  }
  for (auto i = 0; i < t; i++)
    cout << (test[i] ? "first" : "second") << "\n";
} 