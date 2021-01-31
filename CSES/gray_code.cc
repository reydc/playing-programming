// https://cses.fi/problemset/task/2205
#include <iostream>
#include <bitset>
#include <string>
#define MAX 16
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned n;
  cin >> n;
  for (unsigned i = 0; i < (1u << n); i++) {
    cout << (bitset<MAX> (i ^ (i >> 1))).to_string().substr(MAX - n, MAX) << "\n";   
  }
}