// https://cses.fi/problemset/task/1724
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ull = unsigned long long;

inline void matrix_copy(ull* A[], ull* B[],int dim) {
  for (auto i = 0; i < dim; i++) copy(B[i], B[i] + dim, A[i]);
}

inline void matrix_min(ull* A[], ull* B[], ull* C[], int dim) {
  for (auto i = 0; i < dim; i++) {
    for (auto j = 0; j < dim; j++) {
      C[i][j] = ULLONG_MAX;
      for (auto k = 0; k < dim; k++) {
        if (A[i][k] == ULLONG_MAX || B[k][j] == ULLONG_MAX) { 
          C[i][j] = min(C[i][j], ULLONG_MAX); 
        } else if (A[i][k] + B[k][j] < max(A[i][k], B[k][j])) {
          C[i][j] = min(C[i][j], ULLONG_MAX); 
        } else {
          C[i][j] = min(C[i][j], A[i][k] + B[k][j]); 
        }
      }
    }
  }
}

void exp(ull* A[], ull* R[], ull* T[], int dim, int k) {
  if (k == 1) {
    matrix_copy(R, A, dim);
    return;
  }
  while (k) {
    if (k&1) {
      matrix_min(R, A, T, dim);
      matrix_copy(R, T, dim);
    }
    k>>=1;
    matrix_min(A, A, T, dim);
    matrix_copy(A, T, dim);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, a, b, c;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << 0 << "\n";
    return 0;
  }
  ull** ad = new ull* [n];
  ull** res = new ull* [n];
  ull** temp = new ull* [n];
  for (auto i = 0; i < n; i++) {
    ad[i] = new ull [n];
    res[i] = new ull [n];
    temp[i] = new ull [n];
  }
  for (auto i = 0; i < n; i++) {
    fill_n(ad[i], n, ULLONG_MAX);
    fill_n(res[i], n, ULLONG_MAX);
    res[i][i] = 0;
  }  
  for (auto i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (ad[a - 1][b - 1]) {
      ad[a - 1][b - 1] = min(ad[a -1][b - 1], (ull)c);
    } else {
      ad[a - 1][b - 1] = c;
    }
  }
  exp(ad, res, temp, n, k);

  if (ULLONG_MAX == res[0][n - 1]) { 
    cout << -1 << "\n";
  } else {
    cout << res[0][n - 1] << "\n";
  }
  for (auto i = 0; i < n; i++) {
    delete[] ad[i];
    delete[] res[i];
    delete[] temp[i];
  }
  delete[] ad;
  delete[] res;
  delete[] temp;
}