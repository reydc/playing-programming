#include <iostream>
#define abs(k) (k<0?(-k):k)
using namespace std;

int main() {
   int matrix[5][5];
   int moves = 0, r_m = 2, c_m = 2;
   int dif_r, dif_c;
   int r, c;
   bool not_f = true;
   for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
           cin >> matrix[i][j];
           if (not_f && matrix[i][j]) {
               r = i; c = j;
               not_f = !not_f;
           }
       }
   }
   if (r_m == r && c_m == c) {
       cout << moves << endl;
   } else {
       dif_r = r_m - r; dif_c = c_m - c;
       moves = abs(dif_r) + abs(dif_c);
       cout << moves << endl;
   }
   return (0);
}
