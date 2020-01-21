// https://cses.fi/problemset/task/1131
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

void dfs(int s, int& f, int c, int& m_count, vb& visit, vvi& adj) {
  visit[s] = true;
  c++;
  for (auto u:adj[s]) {
    if (!visit[u]) {
      if (c > m_count) {
        m_count = c;
        f = u;
      }
      dfs(u, f, c, m_count, visit, adj);
    }
  }
}

int diameter(int s, vb& visit, vvi& adj) {
  int c = 0;
  int m_count = 0;
  for (unsigned i = 0; i < visit.size(); i++) visit[i] = false;
  int f_1 = 0, f_2 = 0;
  dfs(s, f_1, c, m_count, visit, adj);
  c = 0;
  for (unsigned i = 0; i < visit.size(); i++) visit[i] = false;
  dfs(f_1, f_2, c, m_count, visit, adj);
  return m_count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n;
  vvi adj(n+1);
  vb visit(n+1);
  for (auto i = 1; i <= n-1; i++) {
    cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  cout << diameter(1, visit, adj) << "\n";
}