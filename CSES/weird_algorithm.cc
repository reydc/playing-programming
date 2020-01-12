// https://cses.fi/problemset/task/1068/
#include <iostream>
using namespace std;

int main() {
  unsigned long long n = 1;
  cin >> n;
  while (n != 1) {
      cout << n << " ";
      n % 2 ? n = 3 * n + 1 : n /= 2;
  }
  cout << 1 << endl;
}
