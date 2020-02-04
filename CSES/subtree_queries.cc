// https://cses.fi/problemset/task/1137
#include <iostream>
#include <vector>
#define eb emplace_back
#define M 200001
using namespace std;
using ll = long long;
using vvll = vector<vector<ll>>;
static ll vals[M];
static ll size[M];
static ll tta[M];
static ll pos_tta[M];
static ll bit[M];

void build_bit(ll n) {
  ll* sums = new ll[n+1];
  sums[0] = 0;
  for (auto i = 1; i <= n; i++) sums[i] = sums[i-1] + vals[tta[i]];
  for (auto i = 1; i <= n; i++) bit[i]  = sums[i] - sums[i - (i&-i)];
  delete[] sums;
}

ll sum_bit(ll a) {
  ll sum = 0;
  while (a >= 1) {
    sum += bit[a];
    a -= a&-a;
  }
  return sum;
}

ll sum_range(ll a, ll b) {
  if (a > b) return 0;
  return sum_bit(b) - sum_bit(a-1);
}

inline ll sum(ll s) {
  return sum_range(pos_tta[s], pos_tta[s] + size[s] - 1);
}

inline void update(ll s, ll x, ll max) {
  x -= vals[s];
  vals[s] += x;
  auto in = pos_tta[s];
  while (in <= max) {
    bit[in] += x;
    in += in&-in;
  }
}

ll dfs(ll s, ll f, ll& i, vvll& adj) {
  tta[i] = s;
  pos_tta[s] = i;
  size[s] = 1;
  for (auto u:adj[s]) {
    if (u == f) continue;
    i++;
    size[s] += dfs(u, s, i, adj);
  }
  return size[s];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, q, a, b, t, s, x;
  cin >> n >> q;
  vvll adj(n+1);
  for (auto i = 1; i <= n; i++) cin >> vals[i];
  n--;
  while (n--) {
    cin >> a >> b;
    adj[a].eb(b);
    adj[b].eb(a);
  }
  n = adj.size() - 1;
  auto i = 1LL;
  dfs(1, 0, i, adj);
  build_bit(n);
  for (auto i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> s >> x;
      update(s, x, n);
    } else {
      cin >> s;
      cout << sum(s) << "\n";
    }
  }
}