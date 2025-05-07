#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Vector of strings to write to the file
    vector<string> lines = {
        "Hello, world!",
        "This is a test file.",
        "C++ file handling is easy.",
        "Goodbye!"
    };

    ofstream outFile("output.txt");  // Open file for writing

    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    // Write each string to the file
    for (const string& line : lines) {
        outFile << line << endl;
    }

    outFile.close();  // Close the file
    cout << "Strings have been written to output.txt successfully." << endl;

    return 0;
}
