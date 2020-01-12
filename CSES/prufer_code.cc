/* https://cses.fi/problemset/task/1134 */
/* Algorithm was based on
   An Optimal Algorihtm for Prufer Codes - Xiadong Wang, Lei Wang, Yingjie Wu
*/
#include <iostream>
#include <vector>
#include <queue>
#define ull unsigned long long
#define ll long long
using namespace std;
typedef pair<ull, ull> puu;
static ll d[200001];
static ull code[200000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n, len_code;
  priority_queue<ull,vector<ull>,greater<ull>> nodes;
  vector<puu> E;
  cin >> n;
  len_code = n-2;
  for (ull i = 1; i <= n; i++) {
    d[i] = 1;
  }
  for (ull i = 1; i <= len_code; i++) {
    cin >> code[i];
    d[code[i]]++;
  }
  for (ull i = 1; i <= n; i++) {
    if (d[i] == 1) nodes.push(i);
  }
  
  ull x = nodes.top(), index; index = x;
  nodes.pop();
  for (ull i = 1; i <= len_code; i++) {
    E.push_back({code[i], x});
    d[code[i]]--;
    if (code[i] < index && d[code[i]] == 1) {
      x = code[i];
    } else {
      if (d[code[i]] == 1) nodes.push(code[i]);
      index = x = nodes.top();
      nodes.pop();
    } 
  }
  E.push_back({code[len_code],nodes.top()});
  nodes.pop();
  for (auto p:E) cout << p.first << " " << p.second << "\n";
}