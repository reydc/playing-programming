// https://cses.fi/problemset/task/1091
#include <iostream>
#include <set>
#define MAX 200000
using namespace std;
using ll = long long;

static ll t[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, a;
  // Reverse the order
  multiset<ll, greater<ll>> h;
  cin >> n >> m;
  for (auto i = 0; i < n; i++) {
    cin >> a;
    h.insert(a);
  }
  for (auto i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (auto i = 0; i < m; i++) {
    // Find element <= t[i], this will find nearest
    auto a = h.lower_bound(t[i]);
    if (a != h.end()) {
      cout << *a << "\n";
      // just erase by iterator
      // h.erase(*a) will erase all *a from multiset
      h.erase(a);
    } else {
      cout << -1 << "\n";
    }
  }
}
