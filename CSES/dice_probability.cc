// https://cses.fi/problemset/task/1725 
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double dice_prob(int k) {
  if (1<=k && k<=6) return (double)1/6;
  return (double)0;
}

double prob_conv(vector<vector<double>> &c, int n, int k) {
  if (k < n || k > 6*n) return 0;
  return c[n][k-n];
}

void generate_conv(vector<vector<double>> &c, int n) {
  if (n == 1) {
    for (int i = 1; i <= 6; i++) {
      c[1].push_back((double)1/6); 
    }
  } else if (n > 1) {
    for (int i = n; i <= 6*n; i++) {
      double conv = 0;
      for (int j = 1; j < i; j++) {
        conv +=  prob_conv(c, n-1, j) * dice_prob(i-j);
      }
      c[n].push_back(conv);
    }
  }
}

int main() {
  int n, i = 1, a, b;
  vector<vector<double>> convolutions(101);
  double res = 0;
  cin >> n >> a >> b;
  while (i <= n) {
    generate_conv(convolutions, i++);
  }
  for (i = a; i <= b; i++) {
    res += prob_conv(convolutions, n, i);
  }
  cout << fixed << setprecision(6) << res << "\n";
}