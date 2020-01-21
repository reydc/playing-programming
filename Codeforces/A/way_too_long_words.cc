#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  vector<pair <string,int>> words;
  char f, l;
  cin >> n;
  cin.ignore();
  string temp; pair <string,int> p;
  for (int i = 0; i < n; i++) {
    getline(cin, temp);
    p = make_pair(temp, temp.length());
    words.push_back(p);
  }
  for (int i = 0; i < n; i++) {
    if ((words[i]).second > 10) {
      f = (words[i]).first[0];
      l = (words[i]).first[words[i].second - 1];
      cout << f << (words[i]).second - 2 << l << endl;
    } else {
      cout << (words[i]).first << endl;
    }
  }
  return (0);
}
