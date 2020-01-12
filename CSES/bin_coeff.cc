// https://cses.fi/problemset/task/1079
#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAX 1000001
using namespace std;
typedef unsigned long long ull;
static ull fac[MAX];

void init_fac() {
  fac[0]=1; fac[1]=1; fac[2]=2; fac[3]=6;
  for (ull i = 4; i < MAX; i++) fac[i] = (i*fac[i-1]) % MOD;
}

ull modular_exp(ull base, ull exp, ull mod) {
  ull res = 1;
  while (exp) {
    if (exp&1) res = (res*base)%mod;
    base = (base*base)%mod;
    exp>>=1;
  }
  return res;
}

ull bin_c(ull n, ull k) {
  if (k > n-k) {
    k = n-k;
  }
  ull a = fac[n];
  ull b = modular_exp(fac[k], MOD-2, MOD);
  ull c = modular_exp(fac[n-k], MOD-2, MOD);
  return ( ((a*b)%MOD) * c)%MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n, a, b;
  vector<pair<ull,ull>> q;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    q.push_back({a,b});
  }
  init_fac();
  for (auto p : q) {
    cout << bin_c(p.first, p.second) << "\n";
  }
}