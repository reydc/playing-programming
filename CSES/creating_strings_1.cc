// https://cses.fi/problemset/task/1622
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  string z;
  set<string> p;
  vector<string> pv;
  cin >> z;
  sort(z.begin(), z.end());
  p.insert(z);
  while (next_permutation(z.begin(), z.end())) p.insert(z);
  copy(p.begin(), p.end(), back_inserter(pv));
  sort(pv.begin(), pv.end());
  cout << p.size() << "\n";
  for (auto s : pv) { cout << s << "\n"; }
}