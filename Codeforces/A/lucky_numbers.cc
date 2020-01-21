#include <iostream>
#include <string>
using namespace std;

bool luck_div(int t) {
    int h[10] = {4,7,47,74,447,474,477,744,747,774};
    bool ans = false;
    int i = 0;
    while (!ans && i < 10) {
        ans = ans || t % h[i] == 0;
        i++;
    }
    return (ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int len = s.length();
    bool lucky = true;
    for (int i = 0; i < len; i++) {
        lucky = lucky && (s[i] ==  '4' || s[i] == '7');
    }
    if (lucky) {
        cout << "YES" << endl;
    } else {
        int t = stoi(s);
        if (luck_div(t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return (0);
}
