#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned u;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  u count_B = 0;
  u count_u = 0;
  u count_l = 0;
  u count_b = 0;
  u count_a = 0;
  u count_s = 0;
  u count_r = 0;
  u m1, m2;
  cin >> s;
  u i = 0;
  while (i < s.length()) {
    switch (s[i]) {
      case 'B': count_B++; break;
      case 'u': count_u++; break;
      case 'l': count_l++; break;
      case 'b': count_b++; break;
      case 'a': count_a++; break;
      case 's': count_s++; break;
      case 'r': count_r++; break;
    }
    i++;
  }
  m2 = count_u > count_a ? count_a : count_u;
  if (m2 % 2) m2--;
  m1 = min({count_B, count_l, count_b, count_s, count_r});
  if (m1 == 0 || m2 == 0) {
    cout << 0 << "\n";
  } else {
    if (m2 > m1) {
      while (m2 < 2 * m1 && m1 > 0) {
        m1--;
      }
      cout << m1 << "\n";
    } else {
      cout << m2/2 << "\n";
    }
  }
}