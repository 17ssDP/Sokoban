#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    if(input.length() != 1)
        cout << "length error" << endl;
    cout << input << endl;
}