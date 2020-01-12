// https://cses.fi/problemset/task/1092
/* https://math.stackexchange.com/questions/2596039/whether-a-integer-set-can-be-divided-into-equal-sum-subsets */
#include <iostream>
#include <unordered_set>
#define us unordered_set
#define u unsigned
using namespace std;
int main() {
  u n,s;
  cin >> n;
  s =(n*n+n)>>1;
  if (s&1) {
    cout << "NO\n";
    return 0;
  }
  us<u> A,B;
  while (n>= 4){
    A.insert(n);
    A.insert(n-3);
    B.insert(n-1);
    B.insert(n-2);
    n-=4;
  }
  if (n%4==3) {
    A.insert(1); A.insert(2);
    B.insert(3);
  }
  cout << "YES\n" << A.size() << "\n";
  for (auto a : A) cout << a << " ";
  cout << "\n" << B.size() << "\n";
  for (auto b : B) cout << b << " ";
  cout << "\n";
}