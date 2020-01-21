#include <iostream>
#include <vector>
using namespace std;

bool any_div(vector<int> mkp, int p) {
    bool ans = false;
    int i = 0;
    while (!ans && i < mkp.size()) {
        ans = ans || p % mkp[i] == 0;
        i++;
    }
    return (ans);
}

int new_p(vector<int> mkp) {
    int p = mkp[mkp.size() - 1] + 1;
    while (any_div(mkp, p)) {
        p++;
    }
    return (p);
}

int main() {
    vector<int> pp;
    vector<int> mkp;
    mkp.push_back(2); mkp.push_back(3);
    int n;
    cin >> n;
    int i = 0;
    while (n != 0) {
        if (n - mkp[i] != 1) {
            n = n - mkp[i];
            pp.push_back(mkp[i]);
        } else {
            if (i == mkp.size() - 1) {
                mkp.push_back(new_p(mkp));
                i++;
            } else {
                i++;
            }
        }
    }

    cout << pp.size() << endl;
    for (int i = 0; i < pp.size(); i++) {
        if (i != pp.size() - 1) {
            cout << pp[i] << " ";
        } else {
            cout << pp[i] << endl;
        }
    }
    return (0);
}
