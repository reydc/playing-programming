#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a%b);
}

string frac(int a, int b) {
  int c = gcd(a, b); int n = a/c, d = b/c;
  return to_string(n) + string("/") + to_string(d);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> d;
  string res;
  int s = 0;
  cin >> n;
  for (int i = 2; i < n; i++) {
    int t = n;
    while (t >= i) {
      d.push_back(t % i);
      t /= i;
    }
    d.push_back(t);
  }
  for (unsigned i = 0; i < d.size(); i++) {
    s += d[i];
  }
  cout << frac(s, n - 2) << "\n";
}