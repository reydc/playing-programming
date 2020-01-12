// https://cses.fi/problemset/task/1640
#include <iostream>
#include <map>
using namespace std;
int main() {
  long long n, x, a;
  map<long long, long long> m;
  cin >> n >> x;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    if (m.find(x-a)  != m.end()) {
      cout << m[x-a] << " " << i+1 << "\n";
      return 0;
    }
    m[a] = i+1;
  }
  cout << "IMPOSSIBLE\n";
}