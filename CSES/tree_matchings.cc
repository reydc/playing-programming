// https://cses.fi/problemset/task/1130
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vvi = vector<vector<int>>;

static int m[200001];

void max_matching(int s, int from, vvi& adj) {
  if (adj[s].size() > 0 && m[s] == 0) {
    m[s] = 0;
    for (auto v : adj[s]) {
      if (v == from) continue;
      max_matching(v, s, adj);
    }
    for (auto v : adj[s]) {
      if (v == from) continue;
      int temp = 1;
      for (auto c : adj[v]) {
        if (c != s) temp += m[c];
      }
      for (auto u : adj[s]) {
        if (u != v) temp += m[u];
      }
      m[s] = max(m[s], temp);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n;
  vvi adj(n+1);
  while (cin >> a >> b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  max_matching(1, 0, adj);
  cout << m[1] << "\n";
}