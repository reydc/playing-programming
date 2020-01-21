#include <iostream>
#include <map>
using namespace std;
typedef unsigned u;

int main() {
  u k, n;
  u ans[10]; u side;
  u a[1000];
  map<u, u> m;
  cin >> k;
  for (u i = 0; i < k; i++) {
    cin >> n;
    for (u j = 0; j < n; j++){
      cin >> a[j]; m[a[j]]++;
    }
    side = 1;
    for (u j = 1; j < n + 1; j++) {
      for (u h = j + 1; h < n + 1; h++) {
        m[j] += m[h];
      }
      if (m[j] >= j) side = j; 
    }
    ans[i] = side;
    m.clear();
  }
  for (u i = 0; i < k; i++) {
    cout << ans[i] << "\n";
  } 
}