// https://cses.fi/problemset/task/1633
#include <iostream>
#define MOD 1000000007
#define MAX 1000001
using namespace std;
static long long b[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  b[0] = 1;
  b[1] = 1;
  b[2] = 2;
  b[3] = 4;
  b[4] = 8;
  b[5] = 16;
  b[6] = 32;
  cin >> n;
  for (auto i = 7; i <= n; i++) {
    b[i] = 0;
    for (auto j = 1; j <= 6; j++) {
      b[i] = (b[i] + b[i-j])%MOD;
    }
  }
  cout << b[n] << "\n";
}