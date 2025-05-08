#include <iostream>
#include <fstream>  // For file input
#include <string>
using namespace std;

int main() {
    string filename = "data.txt";  // Name of the file to read
    ifstream inputFile(filename);  // Open file for reading

    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    cout << "Contents of " << filename << ":\n\n";

    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close();  // Close the file
    return 0;
}
