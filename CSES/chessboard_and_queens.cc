// https://cses.fi/problemset/task/1624
#include <iostream>
using namespace std;

static bool reserved[9][9];
static int row[9];
// signal that row[i], 1 <= i <= 8, is being used 
static bool used_row[9];
// Coding the diagonals coded as 2,...,16
// upper_l "\": row - column + 8
static bool used_diag_upper_l[17];
// upper_r "/": row + column
static bool used_diag_upper_r[17];

int queens(int i) {
  if (i == 9) return 1;
  auto c = 0;
  // Use col 1,...,8 with the row[i];
  for (row[i] = 1; row[i] <= 8; row[i]++) {
    if (used_row[row[i]] || used_diag_upper_r[i+row[i]] || used_diag_upper_l[i-row[i]+8] || reserved[i][row[i]]) continue;
    used_row[row[i]] = true;
    used_diag_upper_r[i+row[i]]   = true;
    used_diag_upper_l[i-row[i]+8] = true;
    c += queens(i+1);
    used_row[row[i]] = false;
    used_diag_upper_r[i+row[i]]   = false;
    used_diag_upper_l[i-row[i]+8] = false;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char s;
  for (auto i = 1; i <= 8; i++) {
    for (auto j = 1; j <= 8; j++) {
      cin >> s;
      if (s == '*') reserved[i][j] = true;  
    }
  }
  cout << queens(1) << "\n";
}