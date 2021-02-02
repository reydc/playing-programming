// https://cses.fi/problemset/task/1637
#include <iostream>
#include <string>
#define ZERO 48
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, steps = 0;
  cin >> n;
  while (n != 0) {
    m = 0;
    for (auto c:to_string(n)) m = max(m, (long long)c - ZERO);
    n -= m;
    steps++;
  }
  cout << steps << "\n";
}