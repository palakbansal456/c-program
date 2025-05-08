#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";  // File name for both input and output
    fstream fileStream(filename, ios::in | ios::out | ios::trunc);  // Open file in read and write mode

    if (!fileStream) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    // Writing data to the file
    fileStream << "Hello, this is a test file." << endl;
    fileStream << "We are using fstream for both input and output." << endl;
    fileStream << "This is the third line of text." << endl;

    // Move the file pointer to the beginning of the file to read
    fileStream.seekg(0, ios::beg);

    string line;
    cout << "Reading data from " << filename << ":\n";
    
    // Reading data from the file
    while (getline(fileStream, line)) {
        cout << line << endl;
    }

    fileStream.close();  // Close the file
    return 0;
}
