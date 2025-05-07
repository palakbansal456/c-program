#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string line;

    // Writing to the file using ofstream
    ofstream outFile(filename);  // Open file for writing
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    outFile << "This is a test file.\n";
    outFile << "It contains multiple lines of text.\n";
    outFile << "C++ makes file handling easy.\n";
    outFile.close();  // Close the file after writing

    // Reading from the file using ifstream
    ifstream inFile(filename);  // Open file for reading
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "Contents of the file:\n";
    while (getline(inFile, line)) {
        cout << line << endl;  // Read and display each line
    }

    inFile.close();  // Close the file after reading
    return 0;
}
