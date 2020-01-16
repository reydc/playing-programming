// https://cses.fi/problemset/task/1096
#include <iostream>
#define M 1000000007
using namespace std;
using ull = unsigned long long;
static ull init_part[6];

void matrix_prod(ull** A, ull** B, ull** C, ull mod) {
  for (auto i = 1; i <= 6; i++) {
    for (auto j = 1; j <= 6; j++) {
      C[i][j] = 0;
      for (auto k = 1; k <= 6; k++) {
        C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%mod)%mod;
      }
    }
  }
}

void matrix_copy(ull** DEST, ull** SRC) {
  for (auto i = 1; i <= 6; i++) {
    for (auto j = 1; j <= 6; j++) {
      DEST[i][j] = SRC[i][j];
    }
  }
}

void matrix_power(ull** A, ull** RES, ull n, ull mod) {
  if (n == 1) {
    matrix_copy(RES, A);
  } else {
    ull** T = new ull* [7];
    for (auto i = 1; i <= 6; i++) {
      T[i] = new ull [7];
      for (auto j = 1; j <= 6; j++) {
        T[i][j] = 0;
      }
    }
    
    while (n) {
      if (n&1) {
        matrix_prod(A, RES, T, mod);
        matrix_copy(RES, T);
      }
      matrix_prod(A, A, T, mod);
      matrix_copy(A, T);
      n >>= 1;
    }

    for (auto i = 1; i <= 6; i++) {
      delete[] T[i];
    }
    delete[] T;
  }
}

int main() {
  ios:: sync_with_stdio(0);
  cin.tie(0);
  ull n;
  cin >> n;
  init_part[0] = 1;
  init_part[1] = init_part[0];
  init_part[2] = init_part[0] + init_part[1];
  init_part[3] = init_part[0] + init_part[1] + init_part[2];
  init_part[4] = init_part[0] + init_part[1] + init_part[2] + init_part[3];
  init_part[5] = init_part[0] + init_part[1] + init_part[2] + init_part[3] + init_part[4];
  if (n >= 6) {
    ull** m   = new ull* [7];
    ull** res = new ull* [7];
    for (auto i = 1; i <= 6; i++) {
      m[i]   = new ull [7];
      res[i] = new ull [7];
      if (i <= 5) {
        for (auto j = 1; j <= 6; j++) {
          m[i][j] = (i+1 == j);
          res[i][j] = (i == j);
        }
      } else {
        for (auto j = 1; j <= 6; j++) {
          m[i][j]   = 1;
          res[i][j] = (i == j);
        }     
      }
    }
    ull r = 0;
    matrix_power(m, res, n, M);
    for (auto j = 1; j <= 6; j++) r = (r + (res[1][j]*init_part[j-1])%M)%M;
    for (auto i = 1; i <= 6; i++) {
      delete[] m[i];
      delete[] res[i];
    }
    delete[] m;
    delete[] res;
    cout << r << "\n";
  } else {
    cout << init_part[n] << "\n";
  }
}