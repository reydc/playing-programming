// https://cses.fi/problemset/task/1094
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
  } else if (n > 1 && n < 4) {
    cout << "NO SOLUTION\n";
  } else {
    if (n%2) {
      for (int i = n-1; i > 0; i-=2) {
        cout << i << " ";
      }
      for (int i = n; i > 0; i-=2) {
        cout << i << " ";
      }
    } else {
      for (int i = 2; i <= n; i+=2) {
        cout << i << " ";
      }
      for (int i = 1; i <= n-1; i+=2) {
        cout << i << " ";
      }
    }
  }
}
