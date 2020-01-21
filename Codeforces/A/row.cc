#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n, last; string s; bool maxim;
  cin >> n; cin.ignore();
  getline(cin, s);
  if (n == 1) {
    maxim = s[0] == '1';
  } else if (n == 2) {
    maxim = s[0] != s[1];
  } else {
    maxim = s[0] != s[1];
    last = s[0] - 48;
    unsigned i = 1;
    while (i < n - 2 && maxim) {
      if (last) {
        maxim = s[i] != '1';
        last = s[i] - 48;
      } else {
        maxim = s[i] != s[i+1];
        last = s[i] - 48;
      }
      i++;
    }
    if (maxim) {
      maxim = s[n-2] != s[n-1];
    }
  }
  if (maxim) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return (0);
}
