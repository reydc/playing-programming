#include <iostream>
#include <string>
using namespace std;

static bool is_vowel(char c) {
   c = tolower(c);
   return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

static bool is_cons(char c, string arr) {
   bool it_is = false;
   c = toupper(c);
   for (int i = 0; i < 20; i++) {
       if (it_is = c == arr[i]) {
           break;
       }
   }
   return (it_is);
}

int main() {
   ios::sync_with_stdio(0);
   string consonants = "BCDFGHJKLMNPQRSTVWXZ";
   string input;
   char last;
   
   getline(cin, input, '?');
   int j = input.length() - 1;
   while (j >= 0 && !is_vowel(input[j])) {
       if (!is_cons(input[j], consonants)) {
           j--;
       } else {
           break;
       }
   }
   last = input[j];
   if (is_vowel(last)) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
   return (0);
}
