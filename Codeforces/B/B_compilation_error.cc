#include <iostream>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   long long c1 = 0, c2 = 0, c3 = 0;
   cin >> n;
   long long t;
   for (int i = 0; i < n; i++) {
     cin >> t;
     c1 += t;
   }
   for (int i = 0; i < n - 1; i++) {
     cin >> t;
     c2 += t;
   }
   for (int i = 0; i < n - 2; i++) {
     cin >> t;
     c3 += t;
   }
   cout << c1 - c2 << "\n";
   cout << c2 - c3 << "\n";
}
