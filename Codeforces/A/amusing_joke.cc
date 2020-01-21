#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   bool order;
   string g, h, pile;
   getline(cin, g);
   getline(cin, h);
   getline(cin, pile);
   string g_h = g + h;
   sort(g_h.begin(), g_h.end());
   sort(pile.begin(), pile.end());
   if (pile.length() == g_h.length()) {
       int i = 0;
       while (i < g_h.length()) {
           if (pile[i] != g_h[i]) {
               cout << "NO" << endl;
               break;
           }
           i++;
       }
       if (i == g_h.length()) {
           cout << "YES" << endl;
       }
   } else {
       cout << "NO" << endl;
   }
   return (0);
}
