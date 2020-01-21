#include <iostream>
#include <vector>
using namespace std;
typedef unsigned u;

static bool shaded[50];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  u n, m;
  char c;
  vector<vector<char>> rec;
  cin >> n >> m;
  u min = m, max = 0, from = 0, end = 0;
  bool started = false;
  for (u i = 0; i < n; i++) {
    vector<char> v;
    for (u j = 0; j < m; j++) {
      cin >> c;
      if (c == '*' && !started) { started = true; from = i; }
      if (c == '*' && min > j) { min = j; }
      if (c == '*' && j > max) { max = j; };
      if (c == '*') { shaded[i] = true; }
      v.push_back(c);
    }
    if (shaded[i]) end = i;
    rec.push_back(v);
  }
  for (u i = from; i <= end; i++) {
    for (u j = min; j <= max; j++) {
      cout << rec[i][j];
    }
    if (rec[i].size()) cout << "\n";
  }
}