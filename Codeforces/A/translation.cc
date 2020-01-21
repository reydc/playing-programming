#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    int len;
    bool ok = false;
    getline(cin, s); getline(cin, t);
    if ((len = s.length()) == t.length()) {
        int i = 0, j = len - 1;
        while (i < len) {
            ok = s[i] == t[j];
            i++; j--;
            if (!ok) {
                break;
            }
        }
    }
    ok ? cout << "YES" << endl : cout << "NO" << endl;
    return (0);
}
