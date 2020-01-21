#include <iostream>
#include <vector>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   int n, m;
   int all = 0;
   cin >> n >> m;
   vector<int> bulbs (m);
   int buttons, bulb;
   int i = 0;
   while (i < n) {
       cin >> buttons;
       int j = 0;
       while (j < buttons) {
           cin >> bulb;
           if (!bulbs[bulb - 1]) {
               bulbs[bulb - 1] = 1;
               all++;
           }
           if (all == m) {
               break;
           }
           j++;
       }
       if (all == m) {
           break;
       }
       i++;
   }
   if (all == m) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
   return (0);
}
