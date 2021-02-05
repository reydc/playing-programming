// https://cses.fi/problemset/task/1090
#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;
using ll = long long;

static ll p[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n >> x;
  for (auto i = 0; i < n; i++) cin >> p[i];
  sort(p, p+n);
  ll ans = 0, l = 0, r = n-1;
  // weights being sorted, p[i] <= p[j]
  // so you know that if p[i] + p[j] > x, maybe you can sum
  // below j, and if you found a match then advance index
  while (l <= r) {
    if (l != r && p[l] + p[r] <= x) {
      l++; r--;
    } else {
      r--;
    }
    ans++;
  }
  cout << ans << "\n";
}