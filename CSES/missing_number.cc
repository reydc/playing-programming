// https://cses.fi/problemset/task/1083/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n, x;
    cin >> n;
    if (n == 2) {
        cin >> x;
        x == 1 ? cout << 2 << endl : cout << 1 << endl;
    } else {
        long long j = 1, diff = 1;
        vector <long long> v;
        while (j < n) {
            cin >> x;
            v.push_back(x);
            j++;
        }
        sort(v.begin(), v.end());
        j = 0;
        while (diff == 1 && j < n - 1) {
            diff = v[j + 1] - v[j];
            j++;
        }
        cout << j + 1 << endl;
    }
}
