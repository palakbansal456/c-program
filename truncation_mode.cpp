#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

int main() {
    // File name for demonstration
    string filename = "example.txt";

    // --- 1. Write initial data to the file ---
    cout << "Writing initial data to the file..." << endl;

    ofstream outFile(filename, ios::out);  // Open the file for writing
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Writing data to the file
    outFile << "This is the first line of data.\n";
    outFile << "This is the second line of data.\n";

    // Close the file after writing
    outFile.close();
    cout << "Initial data written to the file." << endl;

    // --- 2. Reopen the file in truncation mode ---
    cout << "\nOpening the file in truncation mode..." << endl;

    ofstream outFileTrunc(filename, ios::out | ios::trunc);  // Open in truncation mode
    if (!outFileTrunc) {
        cerr << "Error: Could not open the file in truncation mode." << endl;
        return 1;
    }

    // Writing new data, which will overwrite the previous content
    outFileTrunc << "This is the new data after truncation.\n";

    // Close the file after writing
    outFileTrunc.close();
    cout << "Data after truncation written to the file." << endl;

    // --- 3. Read the file to verify truncation ---
    cout << "\nReading the file to verify truncation..." << endl;

    ifstream inFile(filename);  // Open the file for reading
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Reading and displaying the content of the file
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;  // Output the content to console
    }

    // Close the file after reading
    inFile.close();

    return 0;
}
