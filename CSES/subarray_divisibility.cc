// https://cses.fi/problemset/task/1662
#include <iostream>
#define MAX_SIZE 200000
#define ll long long
#define ull unsigned long long
using namespace std;
static ull r[MAX_SIZE];
int main() {
  ll n, a, acc = 0;
  ull c = 0;
  bool all_ones = true, all_zeros = true;
  cin >> n;
  for (auto i = 0; i < n; i++) {
    cin >> a;
    if (a != 1) all_ones = false;
    if (a != 0) all_zeros = false;
    acc += a;
    if (acc%n < 0) {
      r[n + (acc%n)]++;
    } else {
      r[acc%n]++;
    }
  }
  if (all_ones) {
    c = 1;
  } else if (all_zeros) {
    c = (n*(n+1))>>1;
  } else {
    c += r[0];
    for (auto i = 0; i < n; i++) {
      if (r[i] > 1) c += (r[i]*(r[i]-1))/2;
    }
  }
  cout << c << "\n";
}