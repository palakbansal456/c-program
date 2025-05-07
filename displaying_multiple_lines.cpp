#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    int numLines;

    // Ask the user how many lines they want to input
    cout << "Enter the number of lines you want to input: ";
    cin >> numLines;
    cin.ignore();  // To clear the newline left by the previous cin

    // Read multiple lines using getline
    cout << "Enter " << numLines << " lines of text:" << endl;
    for (int i = 0; i < numLines; ++i) {
        getline(cin, line);  // Read a full line
        cout << "Line " << i + 1 << ": " << line << endl;  // Display the line
    }

    return 0;
}
