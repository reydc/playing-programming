// https://cses.fi/problemset/task/1084/
#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;
using ll = long long;
static ll a[MAX];
static ll b[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, k, i = 0, j = 0, c = 0;
  cin >> n >> m >> k;
  for (auto i = 0; i < n; i++) cin >> a[i];
  for (auto i = 0; i < m; i++) cin >> b[i];
  sort(a, a+n);
  sort(b, b+m);
  while (i < n && j < m) {
    if (a[i]+k < b[j]) {
      i++;
    } else if (b[j] < a[i]-k) {
      j++;
    }
    else {
      i++;
      j++;
      c++;
    }
  }
  cout << c << "\n";
}