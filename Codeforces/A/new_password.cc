#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
   int length, sym, min;
   string members = "abcdefghijklmnopqrstuvwxyz";
   vector<char> mem_min;
   vector<char> passw;

   cin >> length >> sym;

   min = sym < 26 ? sym : 26;
   for (int i = 0; i < min; i++) {
       mem_min.push_back(members[i]);
   }

   for (int i = 0; i < length; i++) {
       passw.push_back(mem_min[i % min]);
   }
   for (int i = 0; i < length; i++) {
       cout << passw[i];
   }
   cout << "\n";
   return (0);
}
