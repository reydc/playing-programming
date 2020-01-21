#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   set<char> av;
   string name;
   getline(cin, name);
   for (int i = 0; i < name.length(); i++) {
       av.insert(name[i]);
   }
   if (av.size() % 2) {
       cout << "IGNORE HIM!" << endl;
   } else {
       cout << "CHAT WITH HER!" << endl;
   }
   return (0);
}
