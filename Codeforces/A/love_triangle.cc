#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n, p; vector<unsigned> v; bool l = false;
  cin >> n;
  while (n) {
    cin >> p; v.push_back(p); n--;
  }
  p = 0;
  while (p < v.size() && !l) {
    l = (p+1 == v[v[v[p]-1]-1]) || l;
    p++;
  }
  if (l) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return (0);
}
