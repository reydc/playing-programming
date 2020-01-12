// https://cses.fi/problemset/task/1712
#include <iostream>
#include <tuple>
#define M 1000000007
#define M_1 1000000006
#define PHI_M_1 500000002
using namespace std;
typedef unsigned long long ull;
static tuple<ull,ull,ull> queries[100000];

ull mod_exp(ull k, ull e,ull mod) {
  ull res = 1;
  while (e) {
    if (e&1) res = (res*k)%mod;
    k = (k*k)%mod;
    e>>=1;
  }
  return res;
}

int main() {
  ull n, a, b, c;
  cin >> n;
  for (ull i = 0; i < n; i++) {
    cin >> a >> b >> c;
    queries[i] = make_tuple(a,b,c);
  }
  for (ull i = 0; i < n; i++) {
    c = get<2>(queries[i])%PHI_M_1;
    b = mod_exp(get<1>(queries[i]),c,M_1);
    cout << mod_exp(get<0>(queries[i]),b,M) << "\n";
  }
}