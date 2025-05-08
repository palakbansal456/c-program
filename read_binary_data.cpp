#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string filename = "data.bin";  // Name of the binary file to read
    ifstream inputFile(filename, ios::binary);  // Open file in binary mode

    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    // Read the content into a vector of unsigned chars (bytes)
    inputFile.seekg(0, ios::end);  // Move the pointer to the end of the file
    size_t fileSize = inputFile.tellg();  // Get the size of the file
    inputFile.seekg(0, ios::beg);  // Move the pointer back to the beginning of the file

    vector<unsigned char> buffer(fileSize);  // Create a buffer to hold the file content

    inputFile.read(reinterpret_cast<char*>(buffer.data()), fileSize);  // Read data into the buffer

    if (!inputFile) {
        cerr << "Error: Failed to read the file content." << endl;
        return 1;
    }

    // Display the binary data (byte by byte)
    cout << "Binary data read from " << filename << ":\n";
    for (size_t i = 0; i < buffer.size(); ++i) {
        cout << "Byte " << i + 1 << ": " << hex << (int)buffer[i] << endl;
    }

    inputFile.close();  // Close the file
    return 0;
}
