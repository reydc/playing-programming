#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

pll count_d_ld(ll m) {
    pll dig_luck = {0,0};
    while (m) {
        dig_luck.first++;
        if (m%10 == 4 || m%10 == 7) dig_luck.second++;
        m /= 10;
    }
    return dig_luck;
}

bool is_lucky(ll m) {
    pll t = count_d_ld(m);
    return (t.second > 0 ? t.first==t.second : false);
}

bool is_nearly_lucky(ll m) {
    return is_lucky(count_d_ld(m).second);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n; 
    is_nearly_lucky(n)? cout << "YES" << "\n" : cout << "NO" << "\n";
}
