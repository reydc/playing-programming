// https://cses.fi/problemset/task/1652
#include <iostream>
#define ll long long
#define MAX_REC 1001
using namespace std;
static ll s[MAX_REC][MAX_REC];
int main() {
  ll n, q, y1, x1, y2, x2; char c;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      cin >> c;
      s[i][j] = !(c=='.') + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    }
  }
  while (q--) {
    cin >> y1 >> x1 >> y2 >> x2;
    cout << s[y2][x2] - s[y2][x1-1] - s[y1-1][x2] + s[y1-1][x1-1] << "\n";
  }
}