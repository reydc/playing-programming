#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int f = -1;
    int k = 2;
    int ta = 4126; bool da = true, rated = false;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a != b) {
            rated = true;
        }
        if (ta < a && f == -1) {
                f = i;
        }
        da = da && ta >= a;
        ta = a;
    }
    if (rated) {
        k = 1;
    } else if (f != -1) {
        k = 2;
    } else if (da) {
        k = 3;
    }
    switch (k) {
        case 1: cout << "rated" << endl; break;
        case 2: cout << "unrated" << endl ; break;
        case 3: cout << "maybe" << endl; break;
    } 
    return (0);
}
