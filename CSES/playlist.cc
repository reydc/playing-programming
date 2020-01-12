// https://cses.fi/problemset/task/1141
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
  ll a;
  ull n, m = 0, l = 0, r = 0;
  map<ll,ull> l_pos;
  cin >> n;
  for (ull i = 0; i < n; i++) {
    cin >> a;
    if (l_pos.find(a) != l_pos.end() && l <= l_pos[a] && l_pos[a] <= r) {
      m = (m < r-l+1 ? r-l+1 : m);
      l = l_pos[a] + 1;
      r = i;
      l_pos[a] = i;
    } else {
      r = i;
      l_pos[a] = i;
    }
  }
  cout << (m < r-l+1 ? r-l+1 : m) << "\n";
}
