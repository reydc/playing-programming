#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef unsigned u;
map<u, u> m;
vector<pair<u,u>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  u n, t;
  cin >> n;
  for (u i = 0; i < n; i++) {
    cin >> t;
    m[t] = i;
  }
  copy(m.begin(), m.end(), back_inserter<vector<pair<u, u>>>(v));
  sort(v.begin(), 
       v.end(),
       [](pair<u, u>& p, pair<u, u>& q) {
         return p.second < q.second;
       }
      );
  cout << m.size() << "\n";
  for (auto p : v) {
    cout << p.first << " ";
  }
  cout << "\n";
}