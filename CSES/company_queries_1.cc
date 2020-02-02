// https://cses.fi/problemset/task/1687
#include <iostream>
#define MAX 200001
#define EXP 17
using namespace std;
static int a[MAX][EXP + 1];

int ancestor(int x, int k) {
  for (auto i = 0; i <= EXP; i++) {
    if (k & (1<<i)) {
      x = a[x][i];
      if (x == -1) break;
    }
  }
  return x;
}

void pre(int n) {
  for (auto i = 2; i <= n ; i++) {
    for (auto j = 1; j <= EXP; j++) {
      a[i][j] = a[a[i][j-1]][j-1];
      if (a[i][j] == -1) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, e, k;
  cin >> n >> q;
  for (auto j = 0; j <= EXP; j++) {
    a[0][j] = -1;
    a[1][j] = -1;
  }
  for (auto i = 2; i <= n; i++) {
    cin >> a[i][0];
    for (auto j = 1; j <= EXP; j++) a[i][j] = -1;
  }
  pre(n);
  for (auto i = 0; i < q; i++) {
    cin >> e >> k;
    cout << ancestor(e, k) << "\n";
  }
}