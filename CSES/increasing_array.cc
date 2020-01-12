// https://cses.fi/problemset/task/1094
#include <iostream>
using namespace std;
int main() {
  long long n, a, b, m = 0;
  cin >> n;
  cin >> a; n--;
  while (n-- && cin >> b) {
    if (a > b) {
      m += a-b;
      continue;
    }
    a = b;
  }
  cout << m << "\n";
}