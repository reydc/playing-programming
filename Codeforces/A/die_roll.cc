#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b,a%b) : a;
}

string frac(int a, int b) {
  int c = gcd(a,b);
  return to_string(a/c) + string("/") + to_string(b/c);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int y, w;
  cin >> y >> w;
  y || w ? cout << frac(6 - max(y,w) + 1, 6) << "\n" : cout << "0/1\n";
}