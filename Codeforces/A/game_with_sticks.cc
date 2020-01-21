#include <iostream>
#define MIN(a,b) (a < b ? a : b)
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned n,m;
    cin >> n >> m;
    MIN(n,m) % 2 ? cout << "Akshat\n" : cout << "Malvika\n";
}