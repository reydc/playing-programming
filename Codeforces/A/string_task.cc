#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> cons {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};

bool is_consonant(char c) {
    c = tolower(c);
    return (find(cons.begin(), cons.end(), c) != cons.end());
}

int main() {
    string s;
    vector<char> out;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (is_consonant(s[i])) {
            out.push_back('.');
            out.push_back(tolower(s[i]));
        }
    }
    len = out.size();
    for (int i = 0; i < len; i++) {
        cout << out[i];
    }
    cout << endl;
    return (0);
}
