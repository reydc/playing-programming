// https://cses.fi/problemset/task/2183
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<ulong> x;
  ulong n, c;
  cin >> n;
  for (auto i = 0ul; i < n; i++) {
    cin >> c; x.emplace_back(c);
  }
  sort(x.begin(), x.end());
  ulong k = 1;
  for (auto i = 0ul; i < n && x[i] <= k; i++) k += x[i];
  cout << k << "\n";
}