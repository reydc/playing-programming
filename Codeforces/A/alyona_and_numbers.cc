#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  long long int cn0 = 0, cn1 = 0, cn2 = 0, cn3 = 0, cn4 = 0;
  long long int cm0 = 0, cm1 = 0, cm2 = 0, cm3 = 0, cm4 = 0;
  long long int count;
  cin >> n >> m;
  long int i = 1;
  while (i <= n) {
    switch (i%5) {
      case 0: cn0++; break;
      case 1: cn1++; break;
      case 2: cn2++; break;
      case 3: cn3++; break;
      case 4: cn4++; break;
    }
    i++;
  }
  i = 1;
  while (i <= m) {
    switch (i%5) {
      case 0: cm0++; break;
      case 1: cm1++; break;
      case 2: cm2++; break;
      case 3: cm3++; break;
      case 4: cm4++; break;
    }
    i++;
  }
  count = (cn0*cm0)+(cn1*cm4)+(cn2*cm3)+(cn3*cm2)+(cn4*cm1);
  cout << count << endl;
  return (0);
}
