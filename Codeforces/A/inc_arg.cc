#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  unsigned n, c = 0; string s;
  cin >> n; cin.ignore();
  getline(cin, s);
  while (s[c++] != '0' && c < n) {}
  cout << c << endl;
  return (0);
}
