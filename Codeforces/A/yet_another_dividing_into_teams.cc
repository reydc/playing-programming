#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned u;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  u q, n, exists;
  u queries[100];
  int a[100];
  cin >> q;
  for (u i = 0; i < q; i++) {
    cin >> n;
    exists = 0;
    for (u j = 0; j < n; j++) {
      cin >> a[j];
    }
    for (u k = 0; k < n; k++) {
      for (u r = 0; r < n; r++) {
        if (k!=r && abs(a[k] - a[r]) == 1) exists = 1;
      }
    }
    if (exists) { queries[i] = 2; } else { queries[i] = 1; } 
  }
  for (u i = 0; i < q; i++) {
    cout << queries[i] << "\n";
  }
}