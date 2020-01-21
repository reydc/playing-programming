#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    getline(cin, s); getline(cin, t);
    int len = s.length();
    int o1, o2;
    for (int i = 0; i < len; i++) {
        o1 = static_cast<int>(s[i]);
        o2 = static_cast<int>(t[i]);
        cout << (o1 ^ o2);
    }
    cout << endl;
    return (0);
}
