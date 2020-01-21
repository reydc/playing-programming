#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned t;
  ull x,y;
  vector<string> tests;
  cin >> t;
  for (unsigned i = 0; i < t; i++) {
    cin >> x >> y;
    if (x - y != 1) {
      tests.push_back("YES");
    } else {
      tests.push_back("NO");
    }
  }
  for (auto s : tests) {
      cout << s << "\n";
  }
}