#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "Enter a full line of text: ";
    getline(cin, line);  // Read the entire line including spaces

    cout << "\nYou entered: " << line << endl;

    return 0;
}
