// https://cses.fi/problemset/task/1621
#include <iostream>
#include <set>
using namespace std;
typedef unsigned long long ull;
int main() {
  ios::sync_with_stdio(0);
  ull n, x;
  set<ull> s;
  cin >> n;
  while (n--) { cin >> x; s.insert(x); } 
  cout << s.size() << "\n";
}