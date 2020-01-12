// https://cses.fi/problemset/task/1074
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  long long n, x, cost = 0;
  vector<long long> p;
  cin >> n;
  while (n-- && cin >> x) p.push_back(x);
  sort(p.begin(), p.end());
  x = (p.size()%2 ? p[p.size()/2] : (p[p.size()/2]+p[p.size()/2 - 1])/2 );
  for (auto e : p) {
    cost += abs(x-e);
  }
  cout << cost << "\n";
}