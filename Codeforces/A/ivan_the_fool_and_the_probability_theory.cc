// https://codeforces.com/problemset/problem/1239/A
#include <iostream>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;

static ull fibo[100000 + 1];

void fibonacci(ull n) {
  fibo[0] = 1;
  fibo[1] = 1;
  for (ull i = 2; i <= n; i++) {  
    fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n, m, max;
  cin >> n >> m;
  n > m ? max = n : max = m;
  fibonacci(max);
  cout << (2 * (fibo[n] + fibo[m] - 1) ) % MOD << "\n";
}