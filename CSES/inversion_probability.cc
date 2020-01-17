// https://cses.fi/problemset/task/1728
#include <iostream>
#include <iomanip>
using namespace std;
static int r[101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  double res = 0;
  cin >> n;
  for (auto i = 1; i <= n ; i++) cin >> r[i]; 
  for (auto i = 1; i < n; i++) {
    for (auto j = i+1; j <= n; j++) {
      res += (r[i] <= r[j] ? (r[i]-1)*r[i]/(double)2 : r[j]*(r[i]-r[j]+(r[j]-1)/(double)2))/(double)(r[i]*r[j]);
    }
  }
  cout << fixed << setprecision(6) << res << "\n";
}