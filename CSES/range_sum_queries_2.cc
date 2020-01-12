// https://cses.fi/problemset/task/1648
#include <iostream>
#define ll long long
#define MAX 200001
using namespace std;
static ll ar[MAX];
static ll e[MAX];
static ll bit[MAX];
static pair<ll,ll> q[MAX];

ll sum_aux(ll i) {
  ll s = 0;
  while (i >= 1) { 
    s += bit[i];
    i -= i&-i;
  }
  return s;
}

ll sum_bit(ll i, ll j) {
  if (i > 1) return sum_aux(j) - sum_aux(i-1);
  return sum_aux(j);
}

void update_bit(ll i, ll x, ll n) {
  while(i <= n) {
    bit[i] += x;
    i += i&-i;
  }
}

int main() {
  ll n, k, a, b, c;
  cin >> n >> k;
  for (ll i = 1; i <= n; i++) {
    cin >> ar[i];
    e[i] = ar[i] + e[i-1];
    bit[i] = e[i] - e[i-(i&-i)];
  }
  for (ll i = 1; i <= k; i++) {
    cin >> a >> b >> c;
    if (a==1) {
      update_bit(b, c-ar[b], n);
      ar[b] = c;
      q[i] = {a,0};
    } else {
      q[i] = {a,sum_bit(b,c)};
    }
  }
  for (ll i = 1; i <= k; i++) {
    if (q[i].first == 2) cout << q[i].second << "\n";
  }
}