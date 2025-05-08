#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

int main() {
    // Create and open a file for writing
    ofstream outFile("example.txt");

    // Check if the file is successfully opened
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Write some sample data to the file
    outFile << "Hello, this is a test file." << endl;
    outFile << "We will demonstrate seekg and tellg functions." << endl;
    outFile << "File manipulation with file pointers is useful." << endl;

    // Close the file after writing
    outFile.close();

    // Open the file for reading
    ifstream inFile("example.txt");

    // Check if the file is successfully opened
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Step 1: Read and display the first 10 characters of the file
    char ch;
    cout << "Reading first 10 characters:" << endl;
    for (int i = 0; i < 10 && inFile.get(ch); ++i) {
        cout << ch;
    }
    cout << endl;

    // Step 2: Use seekg to move the file pointer
    inFile.seekg(0, ios::beg);  // Move file pointer to the beginning
    cout << "File pointer moved to the beginning." << endl;

    // Step 3: Read and display the first line
    string line;
    getline(inFile, line);
    cout << "First line of the file: " << line << endl;

    // Step 4: Use tellg to get the current position of the file pointer
    cout << "Current file pointer position: " << inFile.tellg() << endl;

    // Step 5: Move the file pointer to the end
    inFile.seekg(0, ios::end);
    cout << "File pointer moved to the end of the file." << endl;
    cout << "Current file pointer position at the end: " << inFile.tellg() << endl;

    // Step 6: Move the file pointer back to the middle (10 bytes from the end)
    inFile.seekg(-10, ios::end);
    cout << "File pointer moved to 10 bytes from the end." << endl;
    cout << "Current file pointer position: " << inFile.tellg() << endl;

    // Step 7: Read and display the data from the current pointer position
    inFile.get(ch);
    cout << "Character at the new position: " << ch << endl;

    // Close the file after reading
    inFile.close();

    return 0;
}
