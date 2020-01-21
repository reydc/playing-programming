#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, x = 0;
  cin >> n; cin.ignore();
  while (n) {
    string s;
    getline(cin, s);
    if (s[0] == '+' || s[s.size()-1] == '+') {
      x++;
    } else if (s[0] == '-' || s[s.size()-1] == '-') {
      x--;
    }
    n--;
  }
  cout << x << endl;
  return (0);
}
