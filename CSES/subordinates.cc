// https://cses.fi/problemset/task/1131
#include <iostream>
#include <vector>
using namespace std;
using vvi = vector<vector<int>>;
static int c[200001];

void dfs_count(int s, int from, vvi& adj) {
  c[s] = 1;
  for (auto v:adj[s]) {
    if (v == from) continue;
    dfs_count(v, s, adj);
    c[s] += c[v];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p;
  cin >> n;
  vvi adj(n+1);
  for (auto i = 2; i <= n; i++) {
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }
  dfs_count(1, 0, adj);
  for (auto i = 1; i <= n; i++) {
    cout << c[i]-1 << " ";
  }
  cout << "\n";
}