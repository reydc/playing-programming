#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n, a, b;
    vector<pair <int,int>> t;
    int c = 0;
    cin >> n;
    cin >> a >> b;
    t.push_back({a,b});
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        for (int j = i - 1; j >= 0; j--) {
            if (a == t[j].second) {
                c++;
            }
            if (b == t[j].first) {
                c++;
            }
        }
        t.push_back({a,b});

    }
    cout << c << endl;
    return (0);
}
