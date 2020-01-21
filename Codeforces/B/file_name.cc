#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n;
  string s;
  cin >> n;
  cin.ignore();
  getline(cin, s);
  s += std::string(1,'#');
  unsigned removed = 0, count = 0;
  for (unsigned i = 0; i < n + 1; i++) {
      if (s[i] == 'x') {
          count++;
      } else {
          if (count > 2) {
              removed += count - 2;
          }
          count = 0;
      }
  }
  cout << removed << "\n";
}