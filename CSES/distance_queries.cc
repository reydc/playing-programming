// https://cses.fi/problemset/task/1135
#include <iostream>
#include <vector>
#include <algorithm>
#define eb emplace_back
#define depth(p) p.first
#define node(p) p.second
#define MAX 200001
#define EXP 18
using namespace std;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
static pi table[2*MAX][EXP + 1];
static pi ett[2*MAX];
static int log2[2*MAX];
static int pos_in_ett[MAX];

void init_log2(int n) {
  log2[1] = 0;
  for (auto i = 2; i < 2*n; i++) log2[i] = log2[i/2] + 1;
}

void build_ett(int s, int from, int& i, int l, vvi& adj) {
  pos_in_ett[s] = i;
  depth(ett[i]) = l;
  node(ett[i])  = s;
  table[i][0] = ett[i];
  for (auto v:adj[s]) {
    if (v == from) continue;
    i++;
    build_ett(v, s, i, l+1, adj);
    depth(ett[i]) = l;
    node(ett[i])  = s;
    table[i][0] = ett[i];
  }
  i++;
}

void build_table(int n) {
  for (auto j = 1; j <= EXP; j++) {
    for (auto i = 1; i + (1<<j) <= 2*n; i++) {
      table[i][j] = ( depth(table[i][j-1]) < depth(table[i + (1<<(j-1))][j-1]) ) ? 
                    table[i][j-1] : 
                    table[i + (1<<(j-1))][j-1];
    }
  }
}

int lca(int a, int b) {
  if (pos_in_ett[a] > pos_in_ett[b]) swap(a,b);
  int j = log2[pos_in_ett[b] - pos_in_ett[a] + 1];
  if (depth(table[pos_in_ett[a]][j]) < depth(table[pos_in_ett[b] - (1<<j) + 1][j])) {
    return node(table[pos_in_ett[a]][j]);
  }
  return node(table[pos_in_ett[b] - (1<<j) + 1][j]);
}

inline int dist(int a, int b) {
  return depth(ett[pos_in_ett[a]]) + depth(ett[pos_in_ett[b]]) - 2 * depth(ett[pos_in_ett[lca(a,b)]]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, a, b, i = 1;
  cin >> n >> q;
  vvi adj(n+1);
  n--;
  while (n--) {
    cin >> a >> b;
    adj[a].eb(b);
    adj[b].eb(a);
  }
  n = adj.size() - 1;
  build_ett(1, 0, i, 0, adj);
  init_log2(n);
  build_table(n);
  while (q--) {
    cin >> a >> b;
    cout << dist(a, b) << "\n";
  }
}