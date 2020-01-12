// https://cses.fi/problemset/task/1643
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  long long n, a, i = 0, max_pos = -1000000000, s = 0, negs = 0, max_neg = -1000000000;
  cin >> n;
  /* Modified Kadane's Algorithm */
  while (i < n && cin >> a) {
    if (a < 0) {
      negs++;
      max_neg = max(max_neg, a);
    }
    s = max(s + a, 0LL);
    max_pos = max(max_pos, s);
    i++;
  }
  if (negs == n) {
    cout << max_neg << "\n";
  } else {
    cout << max_pos << "\n";
  }
}