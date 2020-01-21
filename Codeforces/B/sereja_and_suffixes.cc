#include <iostream>
#include <set>
#define MAX_SIZE 100001
using namespace std;
typedef unsigned u;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  u queries[MAX_SIZE];
  u ne_from[MAX_SIZE];
  u a[MAX_SIZE];
  set<u> diff;
  u n, m;
  cin >> n >> m;
  for (u i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  for (u i = 1; i < m + 1; i++) {
    cin >> queries[i];
  }
  for (u i = n; i > 0; i--) {
    diff.insert(a[i]);
    ne_from[i] = diff.size();
  }
  for (u i = 1; i < m + 1; i++) {
    cout << ne_from[queries[i]] << "\n";
  }
}