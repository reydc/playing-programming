// https://cses.fi/problemset/task/1130
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

// match[i] = j, if (i,j) is in the matching
static int match[200001];
// x[i] -> 1 , node belongs to X set, 0 -> node belong to Y set
static int x[200001];
// distances to 0 vertex
static int d[200001];

// Partition into sets X and Y
void bfs_partition(int s, vi& set_x, vi& set_y, vvi& adj) {
  queue<int> q;
  q.push(s);
  x[s] = 1;
  set_x.push_back(s);

  int current;
  while (q.size() > 0) {
    current = q.front();
    q.pop();
    if (x[current]) {
      for( auto v : adj[current]) {
        if (x[v] == -1) {
          x[v] = 0;
          set_y.push_back(v);
          q.push(v);
        }
      }
    } else {
      for( auto v : adj[current]) {
        if (x[v] == -1) {
          x[v] = 1;
          set_x.push_back(v);
          q.push(v);
        }
      }      
    }
  }
}

int bfs_alt_paths(vi& set_x, vvi& adj) {
  queue<int> q;
  // d[v] == 0 then is free in X, otherwise is matched
  for (auto v : set_x) {
    if (match[v] == 0) {
      d[v] = 0;
      q.push(v);
    } else {
      d[v] = INT_MAX;
    }
  }
  // Shortest distance to 0
  d[0] = INT_MAX;
  int current;
  // This bfs updates the queue with elements from the same set
  while (q.size() > 0) {
    current = q.front();
    q.pop();
    if (d[current] < d[0]) {
      for (auto v : adj[current]) {
        if (d[match[v]] == INT_MAX) {
          d[match[v]] = d[current] + 1;
          q.push(match[v]);
        }
      }
    }
  }
  return d[0] < INT_MAX;
}

int dfs_augment_path(int s, vvi& adj) {
  map<int, int> parent;
  vi starting_elements;
  stack<int> st;
  st.push(s);
  bool is_augmenting = false;
  int last_vertex = -1;
  int current;
  while (st.size() > 0) {
    current = st.top();
    st.pop();
    for (auto v : adj[current]) {
      if (d[match[v]] == d[current] + 1) {
        parent[v] = current;
        parent[match[v]] = v;
        starting_elements.push_back(current);
        if (match[v] == 0) {
          is_augmenting = true;
          last_vertex = v;
          break;
        }
        st.push(match[v]);
      }
    }
    
  }
  if (!is_augmenting) {
    for (auto u : starting_elements) {
      d[u] = INT_MAX;
    }
    return 0;
  } else {
    while (last_vertex != s) {
      if (!x[last_vertex]) {
        match[last_vertex] = parent[last_vertex];
        match[parent[last_vertex]] = last_vertex;
      }
      last_vertex = parent[last_vertex];
    }
    return 1;
  }
}

int hopcroft_karp(vi& set_x, vi& set_y, vvi& adj) {
  for (auto v : set_x) match[v] = 0;
  for (auto v : set_y) match[v] = 0;
  int count = 0;
  while (bfs_alt_paths(set_x, adj)) {
    for (auto v : set_x) {
      if (match[v] == 0 && dfs_augment_path(v, adj)) count++;
    }    
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b; 
  cin >> n;
  vi set_x;
  vi set_y;
  vvi adj(n+1);
  n--;
  while (n--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    x[a] = x[b] = -1;
  }
  bfs_partition(1, set_x, set_y, adj);
  for (auto v : set_y) adj[v].push_back(0);
  cout << hopcroft_karp(set_x, set_y, adj) << "\n";
}