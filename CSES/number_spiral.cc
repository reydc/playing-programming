// https://cses.fi/problemset/task/1071/
#include <iostream>
#include <vector>
using namespace std;

void search_spiral(long long fst, long long snd) {
    if (fst == snd) {
        if (fst == 1) cout << 1 << "\n";
        if (fst > 1) cout << 1 + (fst - 1) * fst << "\n";
    } else {
        if (fst == 1 && snd % 2 == 1) {
            cout << snd * snd << "\n";
        } else if (snd == 1 && fst % 2 == 0) {
            cout << fst * fst << "\n";
        } else if (fst > snd) {
            if (fst % 2 == 1) {
                cout << (fst - 1)*(fst - 1) + snd << "\n";
            } else {
                cout << fst*fst - snd + 1 << "\n";
            }
        } else if (snd > fst) {
            if (snd % 2 == 1) {
                cout << snd*snd - fst + 1 << "\n";
            } else {
                cout << (snd - 1)*(snd - 1) + fst << "\n";
            }
        }
    }
}

int main() {
    long long t = 1, y = 1, x = 1, i;
    vector<pair<long long, long long>> yx;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> y >> x;
        yx.push_back(make_pair(y, x));
    }
    for (i = 0; i < t; i++) {
        search_spiral(yx[i].first, yx[i].second);
    }
    return (0);
}
