// https://cses.fi/problemset/task/1688
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
#define EXP 18
#define eb emplace_back
using namespace std;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;

static pi table[2*MAX][EXP + 1];
static pi ett[2*MAX];
static int log2[2*MAX];
static int pos_in_ett[MAX];

void build_ett(int s, int from, int& step, int level, vvi& adj) {
  pos_in_ett[s]    = step;
  ett[step].first  = level;
  ett[step].second = s;
  table[step][0] = ett[step];
  for (auto v:adj[s]) {
    if (v == from) continue;
    step++;
    build_ett(v, s, step, level + 1, adj);
    ett[step].first  = level;
    ett[step].second = s;
    table[step][0] = ett[step];
  }
  step++;
}

void init_log2(int n) {
  log2[1] = 0;
  for (auto i = 2; i < 2*n; i++) log2[i] = log2[i/2] + 1;
}

void build_table(int n) {
  for (auto j = 1; j <= EXP; j++) {
    for (auto i = 1; i + (1<<j) < 2*n; i++) {
      table[i][j] = (table[i][j-1].first < table[i + (1<<(j-1))][j-1].first) ? 
                    table[i][j-1] : 
                    table[i + (1<<(j-1))][j-1];
    }
  }
}

int lca(int a, int b) {
  if (pos_in_ett[a] > pos_in_ett[b]) swap(a,b);
  int j = log2[pos_in_ett[b] - pos_in_ett[a] + 1];
  return min(table[pos_in_ett[a]][j].second, table[pos_in_ett[b] - (1<<j) + 1][j].second);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, a, b, step = 1;
  cin >> n >> q;
  vvi adj(n+1);
  init_log2(n);
  for (auto i = 2; i <= n; i++) {
    cin >> a;
    adj[a].eb(i);
    adj[i].eb(a);
  }
  build_ett(1, 0, step, 1, adj);
  build_table(n);
  while (q--) {
    cin >> a >> b;
    cout << lca(a, b) << "\n";
  }
}