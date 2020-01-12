// https://cses.fi/problemset/task/1073
#include <iostream>
using namespace std;
typedef long long ll;
static ll t[200001];
int main() {
  ll n, k, i = 1, m, l, r, f = 0, c = 1;
  cin >> n;
  cin >> t[0];
  while (i++ < n) {
    cin >> k;
    l = f; r = c-1;
    m = (l + r)/2;
    while (l < r) {
      if (t[m] <= k) l = m+1;
      if (t[m] > k && t[m-1] <= k) break;
      if (t[m] > k && t[m-1] > k) r = m-1;
      m = (l + r)/2;
    }
    (t[m] > k) ? t[m] = k : t[c++] = k;
    if (k == 1) f++;
  }
  cout << c << "\n";
}