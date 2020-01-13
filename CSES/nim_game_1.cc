// https://cses.fi/problemset/task/1730
#include <iostream>
#define MAX 200000
using namespace std;
static int test[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  long long x;
  cin >> t;
  for (auto i = 0; i < t; i++) {
    cin >> n;
    for (auto j = 0; j < n; j++) {
      cin >> x;
      test[i] ^= x;
    }
  }
  for (auto i = 0; i < t; i++) cout << (test[i] ? "first" : "second") << "\n";  
}