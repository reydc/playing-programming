// https://cses.fi/problemset/task/1629
#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
#define pll pair<ull,ull>
using namespace std;
int main() {
  ull n, a, b, c = 1;
  vector<pll> t;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    t.push_back({a,b});
  }
  sort(t.begin(), t.end(), [](pll& p, pll& q){ return p.second < q.second; });
  b = t[0].second;
  for (ull i = 1; i < t.size(); i++) {
    if (b <= t[i].first) {
      c++;
      b = t[i].second;
    }
  }
  cout << c << "\n";
}