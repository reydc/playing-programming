// https://cses.fi/problemset/task/1723
#include <iostream>
#include <cstring>
#include <algorithm>
#define M 1000000007
using namespace std;
using ll = long long;

inline void matrix_copy(ll* A[], ll* B[],ll dim) {
  for (auto i = 0; i < dim; i++) copy(B[i], B[i] + dim, A[i]);
}

inline void matrix_prod(ll* A[], ll* B[], ll* C[], ll dim, ll mod) {
  for (auto i = 0; i < dim; i++) {
    for (auto j = 0; j < dim; j++) {
      C[i][j] = 0;
      for (auto k = 0; k < dim; k++) {
        C[i][j] = (C[i][j] + A[i][k]*B[k][j])%mod;
      }
    }
  }
}
 
void exp(ll* A[], ll* R[], ll* T[], ll dim, ll k) {
  if (k == 1) {
    matrix_copy(R, A, dim);
    return;
  }
  while (k) {
    if (k&1) {
      matrix_prod(R, A, T, dim, M);
      matrix_copy(R, T, dim);
    }
    k>>=1;
    matrix_prod(A, A, T, dim, M);
    matrix_copy(A, T, dim);
  }
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, k, a, b;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << 0 << "\n";
    return 0;
  }
  ll** ad = new ll* [n];
  ll** res = new ll* [n];
  ll** temp = new ll* [n];
  for (auto i = 0; i < n; i++) {
    ad[i] = new ll [n];
    res[i] = new ll [n];
    temp[i] = new ll [n];
    res[i][i] = 1;
  }
  for (auto i = 0; i < m; i++) {
    cin >> a >> b;
    ad[a - 1][b - 1]++;
  }
  exp(ad, res, temp, n, k);

  cout << res[0][n - 1] << "\n";
  for (auto i = 0; i < n; i++) {
    delete[] ad[i];
    delete[] res[i];
    delete[] temp[i];
  }
  delete[] ad;
  delete[] res;
  delete[] temp;
}
