#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

int main() {
    // Create and open a file for writing
    ofstream outFile("output.txt");

    // Check if the file is successfully opened
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Step 1: Write some initial data to the file
    outFile << "This is a test file." << endl;
    outFile << "We will demonstrate the seekp and tellp functions." << endl;

    // Step 2: Use tellp to get the current position of the put pointer
    cout << "Current put pointer position after writing initial data: " << outFile.tellp() << endl;

    // Step 3: Use seekp to move the put pointer
    outFile.seekp(0, ios::end);  // Move the put pointer to the end of the file
    cout << "Put pointer moved to the end of the file." << endl;

    // Step 4: Use tellp to get the new position of the put pointer
    cout << "Current put pointer position at the end: " << outFile.tellp() << endl;

    // Step 5: Use seekp to move the put pointer to a specific position (10 bytes from the beginning)
    outFile.seekp(10, ios::beg);  // Move the put pointer to the 10th byte from the beginning
    cout << "Put pointer moved to 10 bytes from the beginning." << endl;

    // Step 6: Use tellp to get the current position of the put pointer
    cout << "Current put pointer position after moving: " << outFile.tellp() << endl;

    // Step 7: Write additional data at the new position
    outFile << "This data is written after moving the put pointer." << endl;

    // Close the file after writing
    outFile.close();
    cout << "Data written and file 'output.txt' closed successfully." << endl;

    return 0;
}
