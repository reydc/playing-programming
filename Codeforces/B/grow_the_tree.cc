#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n;
  cin >> n;
  for (unsigned i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long l = 0, r = 0;
  unsigned i = 0, j = n / 2;
  while (i < n / 2 || j < n) {
    if (i < n / 2) l += a[i++];
    if (j < n) r += a[j++];
  }
  cout << l * l + r * r << "\n";
}