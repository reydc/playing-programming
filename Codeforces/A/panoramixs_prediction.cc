#include <iostream>
using namespace std;

bool n_p(int n, int m) {
    bool ans = false;
    int t[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int i = 0;
    while (t[i] != n) {
        i++;
    }
    return (m == t[i + 1]);
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n_p(n,m)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return (0);
}
