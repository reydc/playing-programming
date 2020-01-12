// https://cses.fi/problemset/task/1623
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll min_diff_subsets_sums(vll& w, int size) {
  int N = 2<<(size-1);// N = 2^size = Total subsets
  ll diff, min_s = LLONG_MAX;
  for (auto i = 0; i < N; i++) {
    ll subset_sum = 0, comp_subset_sum = 0;
    for (auto j = 0; j < size; j++) { 
      if (i & (1<<j)) {
        subset_sum += w[j];
      }
      if (~i & (1<<j)) {
        comp_subset_sum += w[j];
      }
    }
    diff = abs(subset_sum-comp_subset_sum);
    if (min_s > diff ) min_s = diff; 
  }
  return min_s;
}

int main() {
  int n; ll w;
  vll weights;
  vll subset_sums;
  cin >> n;
  while(n-- && cin >> w) {
    weights.push_back(w);
  }
  sort(weights.begin(), weights.end());
  cout << min_diff_subsets_sums(weights, weights.size()) << "\n";
}