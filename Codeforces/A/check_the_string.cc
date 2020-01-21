#include <iostream>
#include <string>
using namespace std;

int main() {
   string in;
   int a = 0, b = 0, c = 0;
   bool ans = false;

   getline(cin, in);
   int len = in.length();
   
   int i;
   for (i = 0; in[i] == 'a' && i < len ; i++) {
       a++;
   }
   for (; in[i] == 'b' && i < len; i++) {
       b++;
   }
   for (; in[i] == 'c' && i < len; i++) {
       c++;
   }
   if (ans = (a > 0 && b > 0 && c > 0 && a + b + c == len)) {
       ans = ((a == b && a == c) || (a != b && (a == c || b == c)));
   }
   if (ans) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
   return (0);
}
