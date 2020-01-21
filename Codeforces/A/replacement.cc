#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> a;
    int t;
    int m = 0, pos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > m) {
            m = t; pos = i;
        }
        a.push_back(t); 
    }
    if (m == 1) {
        a[0] = 2;
    } else {
        a[pos] = 1;
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++) {
        i == n -1 ? cout << a[i] : cout << a[i] << " ";
    }
    cout << endl;
    return (0);
}
