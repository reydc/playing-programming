// https://cses.fi/problemset/task/1651
#include <iostream>
#define MAX 200000
#define MAX_POW_2 262144
#define ll long long
using namespace std;
static pair<ll,ll> q[MAX];
static ll ar[MAX];
static ll st[2*MAX_POW_2];

ll get_val_at(ll k, ll start, ll end, ll pos) {
  if (start == end) return st[k];
  ll mid = (start + end)/2;
  if (pos <= mid) {
    return st[k] + get_val_at(2*k, start, mid, pos);
  } else {
    return st[k] + get_val_at(2*k+1, mid+1, end, pos);
  }
}

void update_st(ll k, ll start, ll end, ll i, ll j, ll x) {
  if (i > j) return;
  if (i == start && j == end) {
    st[k] += x;
  } else {
    ll mid = (start + end)/2;
    update_st(2*k, start, mid, i, min(mid,j), x);
    update_st(2*k+1, mid+1, end, max(i,mid+1), j, x);
  }
}

void init_st(ll k, ll start, ll end) {
  if (start == end) {
    st[k] = ar[start];
  } else {
    ll mid = (start + end)/2;
    init_st(2*k,start, mid);
    init_st(2*k+1,mid+1,end);
    st[k] = 0;
  }
}

int main() {
  ll n, st_len = 0, k, a, b, c, d;
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
    for (ll i = 0; i < n; i++) cin >> ar[i];
    for (ll i = n; i < st_len; i++) ar[i] = 0;
    init_st(1,0,st_len-1);
f
  } else {
    for (ll i = 0; i < n; i++) cin >> ar[i];
    init_st(1,0,n-1);
  }
  for (ll i = 0; i < k; i++) {
    cin >> a;
    if (a==1) {
      cin >> b >> c >> d;
      if (st_len) {
        update_st(1,0,st_len-1,b-1,c-1,d);
      } else {
        update_st(1,0,n-1,b-1,c-1,d);
      }
      q[i] = {a,0};
    } else {
      cin >> b;
      if (st_len) {
        q[i] = {a, get_val_at(1,0,st_len-1,b-1)};
      } else {
        q[i] = {a, get_val_at(1,0,n-1,b-1)};
      }
    }
  }
  for (ll i = 0; i < k; i++) {
    if (q[i].first == 2) cout << q[i].second << "\n";
  }
}