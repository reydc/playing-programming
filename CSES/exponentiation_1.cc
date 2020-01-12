// https://cses.fi/problemset/task/1095
#include <iostream>
using namespace std;
typedef unsigned long long ull;
static pair<ull,ull> queries[200000];

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
  ull n, a, b;
  cin >> n;
  for (ull i = 0; i < n; i++) {
    cin >> a >> b;
    queries[i] = make_pair(a,b); 
  }
  for (ull i = 0; i < n; i++) {
    cout << mod_exp(queries[i].first,queries[i].second,1000000007) << "\n";
  }
}