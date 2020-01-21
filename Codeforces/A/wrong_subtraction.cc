#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    while (k) {
        if (n % 10) {
            n--;
        } else {
            n /= 10;
        }
        k--;
    }
    cout << n << endl;
    return (0);
}
