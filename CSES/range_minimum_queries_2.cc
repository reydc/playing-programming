// https://cses.fi/problemset/task/1649
#include <iostream>
#include <climits>
#define MAX 200000
#define MAX_POW_2 262144
#define ll long long
using namespace std;
static pair<ll,ll> q[MAX];
static ll st[2*MAX_POW_2];

ll min_range(ll i, ll j, ll n) {
  i += n; j += n;
  ll m = LONG_LONG_MAX;
  while (i <= j) {
    if (i%2) m = min(m, st[i++]);
    if (!(j%2)) m = min(m, st[j--]);
    i /= 2; j /= 2;
  }
  return m;
}

void update_st(ll i, ll x, ll n) {
  i += n;
  st[i] += x;
  for (i /= 2; 1 <= i; i /= 2) {
    st[i] = min(st[2*i], st[2*i+1]);
  }
}

void init_st(ll l) {
  l /= 2;
  while (l) {
    for (ll i = 0; i < l; i++) {
      st[l+i] = min(st[2*(l+i)], st[2*(l+i) + 1]);
    }
    l /= 2;
  }
}

int main() {
  ll n, st_len = 0, k, a, b, c;
  cin >> n >> k;
  if (n&(n-1)) {
    st_len = n;
    ll c = 0;
    while (st_len) {
      st_len = st_len>>1; c++;
    }
    st_len = 1<<c;
  }
  if (st_len) {
    for (ll i = 0; i < n; i++) cin >> st[st_len+i];
    for (ll i = n; i < st_len; i++) st[st_len+i] = LONG_LONG_MAX;
    init_st(st_len);
  } else {
    for (ll i = 0; i < n; i++) cin >> st[n+i];
    init_st(n);
  }
  for (ll i = 0; i < k; i++) {
    cin >> a >> b >> c;
    if (a==1) {
      if (st_len) {
        update_st(b-1,c-st[st_len+b-1],st_len);
      } else {
        update_st(b-1,c-st[n+b-1],n);
      }
      q[i] = {a,0};
    } else {
      if (st_len) {
        q[i] = {a, min_range(b-1,c-1,st_len)};
      } else {
        q[i] = {a, min_range(b-1,c-1,n)};
      }
    }
  }
  for (ll i = 0; i < k; i++) {
    if (q[i].first == 2) cout << q[i].second << "\n";
  }
}