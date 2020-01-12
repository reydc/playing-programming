// https://cses.fi/problemset/task/1722
#include <iostream>
#define M 1000000007
using namespace std;
typedef unsigned long long ull;

static ull matrix[2][2] = {{1,1}, {1,0}};
static ull res[2][2] = {{1,1}, {1,0}};

void matrix_mul(ull a[2][2],ull b[2][2], ull c[2][2]) {
  ull x = ((a[0][0]*b[0][0])%M + (a[0][1]*b[1][0])%M)%M;
  ull y = ((a[0][0]*b[0][1])%M + (a[0][1]*b[1][1])%M)%M;
  ull z = ((a[1][0]*b[0][0])%M + (a[1][1]*b[1][0])%M)%M;
  ull t = ((a[1][0]*b[0][1])%M + (a[1][1]*b[1][1])%M)%M;
  c[0][0] = x;
  c[0][1] = y;
  c[1][0] = z;
  c[1][1] = t;
}

int main() {
  ull n; cin >> n;
  while (n) {
    if (n&1) matrix_mul(matrix, res, res);
    matrix_mul(matrix, matrix, matrix);
    n >>=1;
  }
  cout << res[1][1] << "\n";
}