// https://cses.fi/problemset/task/1146/
#include <iostream>
using namespace std;
using ull = unsigned long long;

ull count(ull n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (!(n&(n-1))) {
    return 1 + count(n-1);
  }
  ull nn = n, p = 0;
  while (nn>>1) {
    nn>>=1; p++;
  }
  if (!((n+1)&n)) {
    return (p+1)*(1ull<<p);
  }
  return n - (1ull<<p) + 1 + count(n - (1ull<<p)) + count((1ull<<p) - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n;
  cin >> n;
  cout << count(n) << "\n";
}