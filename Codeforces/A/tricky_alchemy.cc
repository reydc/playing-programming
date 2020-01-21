#include <iostream>
using namespace std;

int main() {
  long long A, B;
  long long y, g , b;
  long long counter = 0;
  cin >> A >> B >> y >> g >> b;
  A = A - (2 * y + g);
  B = B - (g + 3 * b);
  if (A >= 0 && B < 0) {
      counter = -B;
  } else if (A < 0 && B >= 0) {
      counter = -A;
  } else if (A < 0 && B < 0 ) {
      counter = -(A  + B);
  }
  cout << counter << endl;
  return (0);
}
