#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

int main() {
    // Step 1: Create and open a file for writing (output file stream)
    ofstream outFile("sample.txt");

    // Check if the file is successfully opened
    if (!outFile) {
        cerr << "Error: Could not create or open the file for writing." << endl;
        return 1;
    }

    // Writing data to the file
    outFile << "Hello, this is a sample file created using file streams." << endl;
    outFile << "File streams allow for reading and writing files in C++." << endl;

    // Close the file after writing
    outFile.close();
    cout << "File 'sample.txt' created and data written successfully." << endl;

    // Step 2: Open the file for reading (input file stream)
    ifstream inFile("sample.txt");

    // Check if the file is successfully opened
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    string line;
    cout << "Reading from 'sample.txt':" << endl;
    
    // Reading data from the file
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the file after reading
    inFile.close();
    cout << "File 'sample.txt' read successfully." << endl;

    return 0;
}
