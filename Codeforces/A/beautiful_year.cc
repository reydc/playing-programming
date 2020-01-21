#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void next_one(char *s) {
    int temp = atoi(s);
    temp++;
    sprintf(s,"%d", temp);
}

bool beauty(char *s) {
    bool t0 = s[0] != s[1] && s[0] != s[2] && s[0] != s[3];
    bool t1 = s[1] != s[2] && s[1] != s[3];
    bool t2 = s[2] != s[3];
    return (t0 && t1 && t2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char *s = (char *)calloc(4, sizeof(char));
    char temp;
    int i = 0;
    while (i < 4) {
        cin >> temp;
        s[i] = temp;
        i++;
    }
    next_one(s);
    while (!beauty(s)) {
        next_one(s);
    }
    cout << s << endl;
    free(s);
    return (0);
}
