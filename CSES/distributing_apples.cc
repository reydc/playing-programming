// https://cses.fi/problemset/task/1716
#include <iostream>
#define M 1000000007
using namespace std;
using ull = unsigned long long;
static ull f[2000000];

ull mod_exp(ull a, ull b, ull m) {
  ull r = 1;
  while (b) {
    if (b&1) r = (r*a)%m;
    a = (a*a)%m;
    b>>=1;
  }
  return r;
}

int main() {
  ull n, m;
  cin >> n >> m;
  f[0] = 1; f[1] = 1; f[2] = 2;
  for (ull i = 3; i <= m+n-1; i++) {
    f[i] = (f[i-1]*i)%M;
  }
  ull k = f[m+n-1];
  ull x = mod_exp((f[m]*f[n-1])%M, M-2, M);
  cout << (k*x)%M << "\n";
}