/* https://cses.fi/problemset/task/1631 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  long long n, t, m = 0, acc = 0;
  vector<long long> st;
  cin >> n;
  while (n--) {
   cin >> t;
   st.push_back(t);
  }
  sort(st.begin(), st.end());
  for (unsigned i = 0; i < st.size(); i++) {
    acc += st[i];
    acc < 2*st[i] ? m = 2*st[i] : m = acc;
  }
  cout << m << "\n";
}