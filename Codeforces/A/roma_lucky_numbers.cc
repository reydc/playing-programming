#include <iostream>
#define FOR(var,init,lim) for (u var=init;var<lim;var++)
using namespace std;
typedef unsigned u;

u count_lucky_digits(u m) {
    u luckies = 0;
    while (m) {
        if (m%10 == 4 || m%10 == 7) luckies++;
        m /= 10;
    }
    return luckies;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    u n,k,ans=0;
    u t;
    cin >> n >> k;
    FOR(i,0,n) {
        cin >> t;
        if (count_lucky_digits(t) <= k) ans++;
    }
    cout << ans << "\n"; 
}
