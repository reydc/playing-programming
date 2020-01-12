// https://cses.fi/problemset/task/1755
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main() {
  int odd_cases = 0;
  char odd = ' ';
  stack<pair<char,int>> rev;
  pair<char,int> p;
  string s, a = "", b = "";
  map<char, int> ord;
  cin >> s;
  for (auto c:s) { ord[c]++; }
  for (auto k:ord) {
    if (k.second%2) {
      odd = k.first;
      odd_cases++;
    } else {
      a += string(k.second/2, k.first);
      rev.push(k);
    }
  }
  if (odd_cases > 1) {
    cout << "NO SOLUTION\n";
  } else if (odd_cases == 1) {
    while (rev.size()) {
      p = rev.top();
      rev.pop();
      b += string(p.second/2, p.first);
    }
    if (ord[odd] > 1) {
      cout << string((ord[odd]-1)/2,odd) + a + string({odd}) + b + string((ord[odd]-1)/2,odd) << "\n";
    } else {
      cout << a + string({odd}) + b << "\n";
    }
  } else {
    while (rev.size()) {
      p = rev.top();
      rev.pop();
      b += string(p.second/2, p.first);
    }
    cout << a + b << "\n";
  }
}