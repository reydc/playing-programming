// https://cses.fi/problemset/task/1072
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, m;
  cin >> n;
  for (ll k = 1; k < n+1; k++) {
    m = 0;
    if (k == 1) m = 0;
    if (k == 2) m = 6;
    if (k == 3) m = 28;
    if (k == 4) m = 96;
    if (k == 5) m = 252;
    if (k > 5) {
      ll sq = k*k;
      ll sq_1 = (k-4)*(k-4);
      m = 4*(sq-3) + 4*(sq-5) + 8*(sq-4) + 4*(k-4)*(sq-5) + 4*(k-4)*(sq-7) + sq_1*(sq-9);
      m /= 2;
    }
    cout << m << "\n";
  }
}