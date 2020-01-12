// https://cses.fi/problemset/task/1618
#include <iostream>
using namespace std;
int main() {
  long long n, c=0;
  cin >> n;
  int i = 5;
  while (n/i >= 1) {
    c += n/i;
    i *=5;
  }
  cout << c << "\n";
}