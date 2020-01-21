#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include <map>
#include <vector>
using namespace std;
typedef unsigned u;
typedef pair<string, u> psu;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  map<string, u> m;  
  vector<psu> v;
  regex date("^((0[1-9]|1[0-9]|2[0-9]|3[01])-(0[13578]|1[02])|(0[1-9]|1[0-9]|2[0-9]|30)-(0[469]|11)|(0[1-9]|1[0-9]|2[0-8])-02)-(2013|2014|2015)$");
  getline(cin, s);
  u n = s.length();
  if (n < 10) cout << "\n";
  if (n == 10 && regex_match(s.begin(), s.end(), date)) {
    cout << s << "\n";
  } else {
    cout << "\n";
  }
  if (n > 10) {
    u i = 0;
    string t = "";
    while (i + 10 <= n) {
      t = s.substr(i, 10);
      if (regex_match(t.begin(), t.end(), date)) {
        if (m.find(t) != m.end()) {
          m[t]++;
        } else {
          m[t] = 1;
        }
      }
      i++;
    }
    if (m.size() > 0) {
      copy(m.begin(), m.end(), back_inserter(v));
      sort(v.begin(), v.end(),
           [](psu& p, psu& q) {
             return p.second < q.second;
           }
      );
      cout << v[v.size() - 1].first << "\n";
    } else {
      cout << "\n";
    }
  }
}