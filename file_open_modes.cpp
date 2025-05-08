#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

int main() {
    // File name for demonstration
    string filename = "example.txt";

    // --- 1. Open the file in write mode (ios::out) ---
    cout << "Opening file in write mode (ios::out)..." << endl;
    ofstream outFile(filename, ios::out);

    // Check if the file is opened successfully
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Writing to the file in write mode
    outFile << "This is the first line written in write mode (ios::out)." << endl;
    outFile << "This file will be overwritten every time it is opened in ios::out." << endl;
    outFile.close();  // Close the file after writing
    cout << "Data written to the file and file closed." << endl;

    // --- 2. Open the file in read mode (ios::in) ---
    cout << "\nOpening file in read mode (ios::in)..." << endl;
    ifstream inFile(filename, ios::in);

    // Check if the file is opened successfully
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Reading from the file in read mode
    cout << "File contents after writing in ios::out mode:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();  // Close the file after reading
    cout << "File read completed and file closed." << endl;

    // --- 3. Open the file in append mode (ios::app) ---
    cout << "\nOpening file in append mode (ios::app)..." << endl;
    ofstream appendFile(filename, ios::app);

    // Check if the file is opened successfully
    if (!appendFile) {
        cerr << "Error: Could not open the file for appending." << endl;
        return 1;
    }

    // Writing additional data to the file in append mode
    appendFile << "This is an additional line written in append mode (ios::app)." << endl;
    appendFile << "Data written in append mode will not overwrite existing content." << endl;
    appendFile.close();  // Close the file after appending
    cout << "Data appended to the file and file closed." << endl;

    // --- 4. Open the file in read mode again (ios::in) to verify appended data ---
    cout << "\nOpening file again in read mode (ios::in) to verify appended data..." << endl;
    inFile.open(filename, ios::in);

    // Check if the file is opened successfully
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Reading the file contents after appending data
    cout << "File contents after appending in ios::app mode:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();  // Close the file after reading
    cout << "File read completed and file closed." << endl;

    return 0;
}
