#include <iostream>
using namespace std;
int main() {
   int shovel_p, coin, minimum = 1, purchase;
   cin >> shovel_p >> coin;
   purchase = minimum * shovel_p;

   while (purchase % 10 && purchase % 10 != coin) {
       minimum++;
       purchase = minimum * shovel_p;
   }
   cout << minimum << endl;
   return (0);
}
