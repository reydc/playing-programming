// https://cses.fi/problemset/task/1628
#include <iostream>
#include <algorithm>
#define ull unsigned long long
#define ll long long
#define MAX 40
#define MAX_SUB 1048576
using namespace std;
static ll t[MAX];
static ll sa[MAX_SUB];
static ll sb[MAX_SUB];
static ull c[MAX+1][MAX+1];

ull comb_num(ull n, ull k) {
  c[1][1] = 1;
  for (ull i = 0; i <= n; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
  }
  for (ull i = 2; i <= n; i++) {
    for (ull j = 1; j < i; j++) {
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  return c[n][k];
}

void get_sum(ll size) {
  ll half = size/2;
  ll pow = 1<<(half);
  ll sum_a, sum_b;
  for (ll i = 0; i < pow; i++) {
    sum_a = sum_b = 0;
    for (ll j = 0; j < half; j++) {
      if (i&(1<<j)) {
        sum_a += t[j];
        sum_b += t[half+j];
      }
    }
    sa[i] = sum_a;
    sb[i] = sum_b;
  }
  sort(sa, sa+pow);
  sort(sb, sb+pow);
}

ll combine(ll target, ll size) { 
  ll pow = 1<<(size/2), c = 0;
  ll i = 0;
  while (i < pow && sa[i] <= target) { 
    auto l = lower_bound(sb, sb+pow, target - sa[i]) - sb;
    if (l < pow) {
      while (l < pow && sb[l] == target - sa[i]) {
        c++;
        l++;
      }
    }
    i++;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  ll n, x;
  bool all_ones = true, all_major = true;
  cin >> n >> x;
  for (auto i = 0; i < n; i++) {
    cin >> t[i];
    if (all_major && t[i] <= x) all_major = false;
    if (all_ones && t[i] != 1) all_ones = false;
  }
  if (all_major) {
    cout << 0 << "\n";
  } else if (all_ones) {
    cout << comb_num(n,x) << "\n";
  } else if (n > 1) {
    get_sum(n);
    cout << combine(x,n) << "\n";
  } else {
    cout << (x == t[0]) << "\n";
  }
}