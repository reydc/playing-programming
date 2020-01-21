#include <iostream>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b){
    unsigned int temp;
    while (b != 0) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return (a);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n, a, b, best;
    cin >> n;
    a = 1;
    b = n - a;
    best = a;
    while (a < b) {
        if (gcd(a,b) == 1) {
            if (best < a) {
                best = a;
            }
        }
        a++;
        b = n - a;
    }
    cout << best << " " << n - best << endl;
    return (0);
}