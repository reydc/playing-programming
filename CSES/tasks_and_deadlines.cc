// https://cses.fi/problemset/task/1630
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  long long n, a, d, f = 0, r = 0;
  vector<pair<long long, long long>> tasks;
  cin >> n;
  while (n--) {
    cin >> a >> d;
    tasks.push_back({a,d});
  }
  sort(tasks.begin(), tasks.end());
  for (auto t : tasks) {
    f += t.first;
    r += t.second - f;
  }
  cout << r << "\n";
}