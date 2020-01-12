// https://cses.fi/problemset/task/1619
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int main() {
  ull n, a, b, max_e = 0, min_e = 1000000000, c = 0, m = 0;
  vector<ull> in, out;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    in.push_back(a);
    out.push_back(b);
    max_e = max({max_e,a,b});
    min_e = min({min_e,a,b});
  }
  n = in.size();
  sort(in.begin(),in.end());
  sort(out.begin(), out.end());
  a = 0; b = 0;
  for (ull k = min_e; k < max_e;) {
    if (in[a] == k) {
      c++; a++;
    }
    if (out[b] == k) {
      c--; b++;
    }
    if (a < n && b < n) {
      k = min(in[a],out[b]);
    } else if (b < n) {
      k = out[b];
    }
    m = max(m,c);
  }
  cout << m << "\n";
}