#include <iostream>
#define M 0
#define E 1
using namespace std;
int main() {
    int n, t = M, w = E;
    cin >> n;
    while (n > 1) {
        if (t == M) {
            if (n % 2 == 0) {
                n = 0;
                w = M;
            } else {
                n--;
            }
            t = E;
        } else {
            if (n % 2 == 1) {
                n = 1;
                w = E;
            } else {
                n--;
            }
            t = M;
        }
    }
    if (w == E) {
        cout << "Ehab" << endl;
    } else {
        cout << "Mahmoud" << endl;
    }
    return (0);
}
