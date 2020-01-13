// https://cses.fi/problemset/task/1729
#include <iostream>
#include <algorithm>
using namespace std;
static bool win[1000001];
static int moves[100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  bool all_W;
  string pos = "W";
  cin >> n >> k;
  for (auto i = 0; i < k; i++) cin >> moves[i];
  sort(moves, moves+k);
  win[1] = true;
  for (auto i = 2; i <= n; i++) {
    all_W = true;
    if (i >= moves[0]) {
      for (auto j = 0; j < k && moves[j] <= i && all_W; j++) {
        all_W = all_W && win[i-moves[j]];
      }
    }
    win[i] = !all_W;
    pos += (win[i] ? "W" : "L");
  }
  cout << pos << "\n";
}