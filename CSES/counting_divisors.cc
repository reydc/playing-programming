// https://cses.fi/problemset/task/1713
#include <iostream>
#include <map>
#define ull unsigned long long
using namespace std;
static ull queries[1000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n, q, c, t;
  cin >> n;
  while (n--) {
    cin >> q;
    if (queries[q]) {
      cout << queries[q] << "\n";
    } else {
      map<ull,ull> f;
      c = 1; t = q;
      for (ull i = 2; i*i <=q ; i++) {
        while (!(q%i)) {
          f[i]++; q/=i;
        }
      }
      if (1 < q) f[q]++;
      for (auto p:f) c *= p.second+1;
      queries[t] = c;
      cout << c << "\n";
    }
  }
}