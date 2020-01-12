// https://cses.fi/problemset/task/1645
#include <iostream>
#include <stack>
static int r[200000];
using namespace std;
using spii = stack<pair<int,int>>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int n, a;
  spii s;
  cin >> n;
  for (auto i = 0; i < n; i++) {
    cin >> a;
    if (s.empty()) {
      s.push({a,i+1});
      r[i] = 0;
    } else {
      while (!s.empty() && s.top().first >= a) {
        s.pop();
      }
      r[i] = (s.empty() ? 0 : s.top().second);
      s.push({a,i+1});
    }
  }
  for (auto i = 0; i < n; i++) {
    cout << r[i] << " ";
  }
}