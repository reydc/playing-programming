#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
   int show_format, h, m;// 12 -> 1-12-1; 24 -> 0-23-0
   string hour_in;
   vector<string> hm;

   cin >> show_format;
   cin.ignore();
   getline(cin, hour_in);
   hm.push_back(hour_in.substr(0,2));
   hm.push_back(hour_in.substr(3,2));
   h = stoi(hm[0]);
   m = stoi(hm[1]);
   if (m >= 60) {
       m = m % 60;
   }

   switch (show_format) {
       case 12:
           if (h == 0) {
               h++;
           } else if (h > 12) {
               while (h > 12) {
                   h = h - 10 ;
               }
           }
       case 24:
           if (h > 23) {
               while (h > 23) {
                   h = h - 10;
               }
           }
   }
   cout << setfill ('0') << setw (2) << h;
   cout << ":"; 
   cout << setfill ('0') << setw (2) << m;
   cout << "\n";
   return (0);
}
