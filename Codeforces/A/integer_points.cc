#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned u;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  ll n, m, temp;
  ll even_p = 0, odd_p = 0, even_q = 0, odd_q = 0;
  vector<ll> p;
  vector<ll> q;
  cin >> t;
  cin >> n;
  for (auto i = 0; i < n; i++) {
    cin >> temp;
    temp % 2 ? odd_p++ : even_p++;
    p.push_back(temp);
  }
  cin >> m;
  for (auto i = 0; i < m; i++) {
    cin >> temp;
    temp % 2 ? odd_q++ : even_q++;
    q.push_back(temp);
  }
  cout << odd_p * odd_q + even_p * even_q << "\n";
}