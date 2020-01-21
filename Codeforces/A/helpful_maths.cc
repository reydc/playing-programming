#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s; vector<char> t;
    getline(cin,s); int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '1' || s[i] == '2' || s[i] == '3') {
            t.push_back(s[i]);
        }
    }
    sort(t.begin(),t.end());
    for (int i = 0; i < t.size(); i++) {
        if (i != t.size() - 1) {
            cout << t[i] << "+";
        } else {
            cout << t[i] << endl;
        }
    }
    return(0);
}
