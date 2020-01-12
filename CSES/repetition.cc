/* https://cses.fi/problemset/task/1069 */
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  char last;
  int m = 1, c = 1, l;
  cin >> s;
  l = s.length();
  if (l == 1) {
    cout << m << "\n";
    return 0;
  }
  last = s[0];
  int i = 1;
  while (i < l) {
    last == s[i] ? c++ : c = 1; last = s[i++];
    m = c > m ? c : m;
  }
  cout << m << "\n";
}