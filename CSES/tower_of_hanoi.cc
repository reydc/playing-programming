// https://cses.fi/problemset/task/2165
#include <iostream>
#include <bitset>
#define MAX (sizeof(ulong) * 8)
using namespace std;
static ulong disk_stack[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

ulong disk_to_move(ulong m) {
  ulong p = 0;
  while(m != 0) {
    m >>= 1;
    p++;
  }
  return p;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unsigned curr_pos, next_pos, disk;
  bitset<MAX> last_move (0), curr_move;
  ulong n;
  cin >> n;
  cout << ((1u << n) - 1) << "\n";
  for (ulong i = 1; i < (1u << n); i++) {
    curr_move = bitset<MAX> (i ^ (i >> 1));
    disk = disk_to_move((last_move ^ curr_move).to_ulong());
    curr_pos = disk_stack[disk];
    if (disk == 1) {
      if ((n & 1) && disk_stack[1] == 1) {
        next_pos = 3;
      } else if ((n & 1) && disk_stack[1] == 3) {
        next_pos = 2;
      } else if ((n & 1) && disk_stack[1] == 2) {
        next_pos = 1;
      } else if (!(n & 1) && disk_stack[1] == 1) {
        next_pos = 2;
      } else if (!(n & 1) && disk_stack[1] == 2) {
        next_pos = 3;
      } else {
        // else if (!(n & 1) && disk_stack[1] == 3) {
        next_pos = 1;
      }
    } else {
      if ((disk_stack[1] == 1 && disk_stack[disk] == 2) || (disk_stack[1] == 2 && disk_stack[disk] == 1)) {
        next_pos = 3;
      } else if ((disk_stack[1] == 2 && disk_stack[disk] == 3) || (disk_stack[1] == 3 && disk_stack[disk] == 2)) {
        next_pos = 1;
      } else {
        // else if ((disk_stack[1] == 1 && disk_stack[disk] == 3) || (disk_stack[1] == 3 && disk_stack[disk] == 1))
        next_pos = 2;
      }
    }
    cout << curr_pos << " " << next_pos << "\n";
    disk_stack[disk] = next_pos;
    last_move = curr_move;
  }
}