#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  unsigned n, m, t, mi = 0;
  vector<unsigned> cap;
  cin >> n >> m;
  while (n) {
    cin >> t;
    cap.push_back(t);
    n--;
  }
  sort(cap.begin(), cap.end());
  while (m > 0) {
    
    if (cap.back() < m) {
      m -= cap.back(); mi++;
    } else {
      mi++;
      m = 0;
    }
    cap.pop_back();
  }
  cout << mi << endl;
  return (0);
}
