// https://cses.fi/problemset/task/1646
#include <iostream>
#define ull unsigned long long
using namespace std;
static ull a[200001];
static ull q[200001];
int main() {
  ull n, k, b, c;
  cin >> n >> k;
  for (ull i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  for (ull i = 1; i <= k; i++) {
    cin >> b >> c;
    if (b==1) {
      q[i] = a[c];
    } else {
      q[i] = a[c] - a[b-1];
    } 
  }
  for (ull i = 1; i <= k; i++) cout << q[i] << "\n";
}