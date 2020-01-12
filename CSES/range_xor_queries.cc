// https://cses.fi/problemset/task/1650/
#include <iostream>
#define MAX 200000
#define MAX_POW_2 262144
#define ll long long
using namespace std;
static ll q[MAX];
static ll st[2*MAX_POW_2];

ll xor_range(ll i, ll j, ll n) {
  i += n; j += n;
  ll r = 0;
  while (i <= j) {
    if (i%2) r ^=  st[i++];
    if (!(j%2)) r ^= st[j--];
    i /= 2; j /= 2;
  }
  return r;
}

void init_st(ll l) {
  l /= 2;
  while (l) {
    for (ll i = 0; i < l; i++) {
      st[l+i] = st[2*(l+i)]^st[2*(l+i) + 1];
    }
    l /= 2;
  }
}

int main() {
  ll n, st_len = 0, k, a, b;
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
    for (ll i = n; i < st_len; i++) st[st_len+i] = 0;
    init_st(st_len);
  } else {
    for (ll i = 0; i < n; i++) cin >> st[n+i];
    init_st(n);
  }
  for (ll i = 0; i < k; i++) {
    cin >> a >> b;
    if (st_len) {
      q[i] = xor_range(a-1,b-1,st_len);
    } else {
      q[i] = xor_range(a-1,b-1,n);
    }
  }
  for (ll i = 0; i < k; i++) cout << q[i] << "\n";
}