// https://cses.fi/problemset/task/1635
#include <iostream>
#define MOD 1000000007
#define MAX 1000001
#define COINS 100
using namespace std;
using ll = long long;

static ll c[COINS];
static ll count[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n >> x;
  for (auto i = 0; i < n; i++) cin >> c[i];
  count[0] = 1;
  for (auto i = 1; i <= x; i++) {
    for (auto j = 0; j < n; j++) {
      if (i - c[j] >= 0) count[i] = (count[i] + count[i - c[j]])%MOD;
    }
  }
  cout << count[x] << "\n";
}