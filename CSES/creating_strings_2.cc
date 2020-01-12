// https://cses.fi/problemset/task/1715
#include <iostream>
#include <map>
#define ll long long
#define M 1000000007
using namespace std;
static ll fac[1000000];
ll mod_exp(ll a, ll b, ll m) {
  a %= m;
  b %= m-1;
  ll res = 1;
  while (b) {
      if (b & 1) res = (res * a)%m;
      a = (a * a)%m;
      b >>= 1;
  }
  return res;
}

ll inver(ll a, ll m) {
  return mod_exp(a, m-2, m);
}

int main() {
  string s; map<char,ll> oc;
  cin >> s;
  ll n = s.size();
  for (auto c:s) {
    oc[c]++;
  }
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = (i*fac[i-1])%M;
  }
  n = 1;
  for (auto p:oc) {
    n = (n * inver(fac[p.second], M))%M;
  }
  cout << (fac[s.size()]*n)%M << "\n";
}