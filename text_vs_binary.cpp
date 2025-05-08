#include <iostream>
#include <fstream>  // For file stream operations
#include <cstring>  // For using strlen()

using namespace std;

int main() {
    // File name for demonstration
    string filename = "example.txt";

    // --- 1. Write data in text mode (default mode) ---
    cout << "Writing data in text mode (default)..." << endl;

    ofstream outFileText(filename, ios::out);  // Open in text mode (default)

    // Check if the file is opened successfully
    if (!outFileText) {
        cerr << "Error: Could not open the file for writing in text mode." << endl;
        return 1;
    }

    // Writing text data to the file in text mode
    outFileText << "This is a test message written in text mode.\n";
    outFileText << "This mode is human-readable.\n";

    // Close the file after writing
    outFileText.close();
    cout << "Data written in text mode and file closed." << endl;

    // --- 2. Write data in binary mode ---
    cout << "\nWriting data in binary mode..." << endl;

    // Open the file in binary write mode
    ofstream outFileBinary(filename, ios::out | ios::binary);

    // Check if the file is opened successfully
    if (!outFileBinary) {
        cerr << "Error: Could not open the file for writing in binary mode." << endl;
        return 1;
    }

    // Writing binary data to the file
    const char* binaryText = "This is a test message written in binary mode.";
    outFileBinary.write(binaryText, strlen(binaryText));

    // Close the file after writing
    outFileBinary.close();
    cout << "Data written in binary mode and file closed." << endl;

    // --- 3. Read data from file in text mode ---
    cout << "\nReading data from file in text mode..." << endl;

    ifstream inFileText(filename, ios::in);  // Open in text mode (default)

    // Check if the file is opened successfully
    if (!inFileText) {
        cerr << "Error: Could not open the file for reading in text mode." << endl;
        return 1;
    }

    // Read and display the contents of the file in text mode
    string line;
    while (getline(inFileText, line)) {
        cout << "Text Mode Read: " << line << endl;
    }

    // Close the file after reading
    inFileText.close();

    // --- 4. Read data from file in binary mode ---
    cout << "\nReading data from file in binary mode..." << endl;

    ifstream inFileBinary(filename, ios::in | ios::binary);  // Open in binary read mode

    // Check if the file is opened successfully
    if (!inFileBinary) {
        cerr << "Error: Could not open the file for reading in binary mode." << endl;
        return 1;
    }

    // Read and display the binary contents of the file
    char buffer[1024];  // Buffer to store binary data
    inFileBinary.read(buffer, sizeof(buffer));

    // Output the binary data as a string
    cout << "Binary Mode Read: " << buffer << endl;

    // Close the file after reading
    inFileBinary.close();

    return 0;
}
