// https://cses.fi/problemset/task/1739
#include <iostream>
#define ll long long
#define M 200000
#define N 1000
#define MAX_POW_2 1024
using namespace std;
static pair<ll,ll> query[M];
static ll m[N][N];
static ll* main_st[2*MAX_POW_2];

// Create dummy segment tree for filling the main_st;
ll* create_dummy_leaf(ll size) {
  ll* st = (ll*)calloc(2*size,sizeof(ll));
  // Put column elements as leaves of tree
  for (ll i = 0; i < size; i++) {
    st[size+i] = 0;
  }
  size /= 2;
  while (size) {
    for (ll i = 0; i < size; i++) {
      st[size+i] = st[2*(size+i)] + st[2*(size+i)+1];
    }
    size /= 2;
  }
  return st;
}

// Create the segment trees for the column in the matrix
ll* create_st_leaf(ll j, ll size, ll original_size) {
  ll* st = (ll*)calloc(2*size,sizeof(ll));
  // Put column elements as leaves of tree
  for (ll i = 0; i < original_size; i++) {
    st[size+i] = m[i][j];
  }
  for (ll i = original_size; i < size; i++) {
    st[size+i] = 0;
  }
  // Get next levels 
  size /= 2;
  while (size) {
    for (ll i = 0; i < size; i++) {
      st[size+i] = st[2*(size+i)] + st[2*(size+i)+1];
    }
    size /= 2;
  }
  return st;
}

ll* compress_level(ll left, ll right, ll size) {
  ll* st = (ll*)calloc(2*size, sizeof(ll));
  // Compress left and right columns by rows operations 
  for (ll i = 0; i < size; i++) {
    st[size+i] = main_st[left][size+i] + main_st[right][size+i];
  }
  // Get next levels
  size /= 2;
  while (size) {
    for (ll i = 0; i < size; i++) {
      st[size+i] = st[2*(size+i)] + st[2*(size+i)+1];
    }
    size /= 2;
  }
  return st;
}

// Destroy segment trees
void destroy_main_st(ll size) {
  for (ll i = 0; i < 2*size; i++) {
    free(main_st[i]);
  }
}

// Fill the main_st with segment trees in the nodes for the columns
void init_main_st(ll size, ll original_size) {
  // Create leafs for the tree
  for (ll j = 0; j < original_size; j++) {
    main_st[size+j] = create_st_leaf(j, size, original_size);
  }
  for (ll j = original_size; j < size; j++) {
    main_st[size+j] = create_dummy_leaf(size);
  }
  // main_st[size+j] = Segment Tree for column j
  // Now, freely create interior nodes
  ll level = size/2;
  while (level) {
    for (ll i = 0; i < level; i++) {
      main_st[level+i] = compress_level(2*(level+i), 2*(level+i)+1, size);
    }
    level /= 2;
  }
}

void add(ll st[], ll index, ll size, ll x) {
  index += size;
  st[index] += x;
  // Add to parents
  for (index /= 2; index >= 1; index /= 2) {
    st[index] = st[2*index] + st[2*index+1];
  }
}

void add_at(ll i, ll j, ll size, ll x) {
  // Add to corresponding leaf
  add(main_st[size+j], i, size, x);
  // Add to corresponding parents of leaf
  ll parent = (size+j)/2;
  while (parent) {
    add(main_st[parent], i, size, x);
    parent /= 2;
  }
}

ll sum_range(ll r1, ll r2, ll st[], ll size) {
  r1 += size; r2 += size;
  ll s = 0;
  while (r1 <= r2) {
    if (r1%2) s += st[r1++];
    if (!(r2%2)) s+= st[r2--];
    r1 /= 2; r2 /= 2;
  }
  return s;
}

ll sum(ll y1, ll x1, ll size) {
  x1 += size;
  ll start = size;
  ll s = 0;
  while ( start <= x1) {
    if (start%2) s += sum_range(0, y1, main_st[start++], size);
    if (!(x1%2)) s += sum_range(0, y1, main_st[x1--], size);
    start /= 2; x1 /= 2;
  }
  return s;
}

ll sum_coord(ll y1,ll x1, ll y2, ll x2, ll size) {
  ll s = 0;
  if (y1==y2 && x1==x2) return m[y1][x1];
  if (y1==0 && x1==0) return sum(y2,x2,size);
  if (y1==0 && x1!=0) return sum(y2,x2,size) - sum(y2,x1-1,size);
  if (y1!=0 && x1==0) return sum(y2,x2,size) - sum(y1-1,x2,size);
  if (y1 <= y2 && x1 <= x2) {
    s += sum(y2,x2,size) - sum(y2,x1-1,size) - sum(y1-1,x2,size) + sum(y1-1,x1-1,size);
  }
  return s;
}

#ifdef DEBUG
void print_st(ll st[], ll size) {
  for (ll i = 0; i < size; i++) {
    cout << st[size+i] << " ";
  }
  cout << "\n";
  size /= 2;
  while (size) {
    for (ll i = 0; i < size; i++) {
      cout << st[size+i] << " ";
    }
    cout << "\n";
    size /= 2;
  }
}

void print_main_st(ll size) {
  cout << "Printing leaves of main_st\n";
  for (ll i = 0; i < size; i++) {
    print_st(main_st[size+i], size);
  }
  ll level = size/2;
  while (level) {
    cout << "Printing new level with " << level << " elements\n";
    for (ll i = 0; i < level; i++) {
      print_st(main_st[level+i],size);
    }
    level /= 2;    
  }
}
#endif

int main() {
  ll n, q, full_len = 0; char f;
  ll a, b, c, d, e;
  cin >> n >> q;
  if (n&(n-1)) {
    full_len = n;
    ll c = 0;
    while (full_len) {
      full_len = full_len>>1; c++;
    }
    full_len = 1<<c;
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> f;
      m[i][j] = !(f=='.');
    }
  }
  if (full_len) {
    init_main_st(full_len,n);
  } else {
    init_main_st(n,n);
  }
  #ifdef DEBUG
  cout << "Printing main_st\n";
  if (full_len) {
    print_main_st(full_len);
  } else {
    print_main_st(n);
  }
  #endif
  for (ll i = 0; i < q; i++) {
    cin >> a;
    if (a==1) {
      cin >> b >> c;
      if (full_len) {
        add_at(b-1, c-1, full_len, (m[b-1][c-1]?-1:1));
        m[b-1][c-1] = (m[b-1][c-1]?0:1);
        query[i] = {a,0};
      } else {
        add_at(b-1, c-1, n, (m[b-1][c-1]?-1:1));
        m[b-1][c-1] = (m[b-1][c-1]?0:1);
        query[i] = {a, 0};
      }
      #ifdef DEBUG
      cout << "Printing main_st after update\n";
      if (full_len) {
        print_main_st(full_len);
      } else {
        print_main_st(n);
      }
      #endif
    } else {
      cin >> b >> c >> d >> e;
      if (full_len) {
        query[i] = {a, sum_coord(b-1, c-1, d-1, e-1, full_len)};
      } else {
        query[i] = {a, sum_coord(b-1, c-1, d-1, e-1, n)};
      }
    }
  }
  for (ll i = 0; i < q; i++) {
    if (query[i].first == 2) cout << query[i].second << "\n";
  }
  if (full_len) {
    destroy_main_st(full_len);
  } else {
    destroy_main_st(n);
  }
}