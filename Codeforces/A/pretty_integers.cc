#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned n, m, t;
  vector<unsigned> v;
  unsigned aa[9] = {0,0,0,0,0,0,0,0,0}, bb[9] = {0,0,0,0,0,0,0,0,0};
  cin >> n >> m;
  while (n--) { cin >> t; aa[t-1] = 1; }
  while (m--) { cin >> t; bb[t-1] = 1; }
  for (unsigned i=0; i<9; i++) {
      for (unsigned j=0; j<9; j++) {
          if (aa[i] && bb[j]) {
              if (i==j) {
                  v.push_back(i+1);
              }
              if (i!=j) { 
                  v.push_back((i+1)*10+(j+1));
                  v.push_back((j+1)*10+(i+1));
              }
          }
      } 
  }
  sort(v.begin(),v.end());
  cout << v.front() << "\n";
}
