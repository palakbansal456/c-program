#include <iostream>
#include <fstream>  // For file stream operations
#include <cstring>  // For using strlen

using namespace std;

int main() {
    // File name for demonstration
    string filename = "binary_example.dat";

    // --- 1. Writing binary data to the file ---
    cout << "Writing binary data to the file..." << endl;

    // Open file in binary write mode
    ofstream outFile(filename, ios::out | ios::binary);  
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Data to be written (an integer and a string)
    int number = 12345;
    const char* text = "Hello, Binary File!";

    // Writing an integer to the file (binary)
    outFile.write(reinterpret_cast<char*>(&number), sizeof(number));
    
    // Writing a string to the file (binary)
    outFile.write(text, strlen(text) + 1);  // Include null-terminator

    // Close the file after writing
    outFile.close();
    cout << "Binary data written to the file." << endl;

    // --- 2. Reading binary data from the file ---
    cout << "\nReading binary data from the file..." << endl;

    // Open file in binary read mode
    ifstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Reading the integer from the file
    int readNumber;
    inFile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));

    // Reading the string from the file
    char buffer[50];  // Assuming the string won't exceed 50 characters
    inFile.read(buffer, sizeof(buffer));

    // Close the file after reading
    inFile.close();

    // Display the read data
    cout << "Read number: " << readNumber << endl;
    cout << "Read string: " << buffer << endl;

    return 0;
}
