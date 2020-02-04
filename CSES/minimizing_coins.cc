// https://cses.fi/problemset/task/1634
#include <iostream>
#define MAX 1000001
#define COINS 100
using namespace std;
using ll = long long;

static ll c[COINS];
static ll min_coins[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n >> x;
  for (auto i = 0; i < n; i++) cin >> c[i];
  min_coins[0] = 0;
  for (auto i = 1; i <= x; i++) {
    min_coins[i] = MAX;
    for (auto j = 0; j < n; j++) {
      if (i - c[j] >= 0) min_coins[i] = min(min_coins[i], min_coins[i - c[j]] + 1);
    }
  }
  cout <<(min_coins[x] == MAX ? -1 : min_coins[x]) << "\n";
}