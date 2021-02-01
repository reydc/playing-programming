// https://cses.fi/problemset/task/2216
#include <iostream>
#define MAX (unsigned)(2*10e5)
using namespace std;
static unsigned pos[MAX + 1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n, k, c = 1;
  cin >> n;
  for (auto i = 0u; i < n; i++) {
    cin >> k; pos[k] = i;
  }
  for (auto i = 1u; i <= n; i++) {
    if (pos[i - 1] > pos[i]) c++;
  }
  cout << c << "\n";
} 