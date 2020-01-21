#include <iostream>
#include <vector>
#define FOR(a,aa) for (u a=0;a<aa;a++) 
using namespace std;
typedef unsigned u;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    u m, n;
    u mm=1;
    cin >> m >> n;
    vector<vector<u>> grid(m);
    FOR(i,m){
        FOR(j,n) {
            (grid[i]).push_back(0);
        }
    }
    FOR(i,m) {
        FOR(j,n) {
            if (!grid[i][j] && i+1<m && !grid[i+1][j]) {
                grid[i][j] = grid[i+1][j] = mm;
                mm++;
            } else if (!grid[i][j] && j+1<n && !grid[i][j+1]) {
                grid[i][j] = grid[i][j+1] = mm;
                mm++;
            }
        }
    }
    cout << mm-1 << "\n";
}
