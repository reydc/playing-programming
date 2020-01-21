#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ul;
typedef vector<ul> vul;

ul elements_after(ul steps, vul& v) {
    if (steps == 0) v[0] = 1; 
    if (!v[steps]) {
        v[steps-1] = elements_after(steps-1, v);
        v[steps] = 2*v[steps-1]+1;
    }
    return v[steps];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ul n;
    ul k;
    cin >> n >> k;
    ul max_el = n;
    vul count_el(n, 0);
    n--;
    ul r = elements_after(n,count_el);
    while (max_el) { 
        if (k == (r+1)/2) {
            cout << max_el << "\n";
            break;
        } else {
            if (k > (r+1)/2 ) k -= (r+1)/2;
            n--;
            r = elements_after(n,count_el);
        }
        max_el--;
    }
}
