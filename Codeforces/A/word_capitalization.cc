#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    input[0] = toupper(input[0]);
    cout << input << endl;
    return (0);
}
