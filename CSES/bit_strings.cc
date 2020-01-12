// https://cses.fi/problemset/task/1617
#include <iostream>
#define MOD 1000000007
using namespace std;
int main() {
  unsigned n, res = 1;
  cin >> n;
  while (n--) {
    res = (res<<1)%MOD;
  }
  cout << res << "\n";
}