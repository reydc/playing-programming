#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int t[4] = {1,1,2,1};
    getline(cin,s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='h' && t[0]){
            t[0]--;
        } else if (s[i]=='e' && !t[0] && t[1]) {
            t[1]--;
        } else if (s[i]=='l' && !t[1] && t[2]) {
            t[2]--;
        } else if (s[i]=='o' && !t[2] && t[3]) {
            t[3]--;
        }
    }
    if (!(t[0] + t[1] + t[2] + t[3])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return (0);
}
