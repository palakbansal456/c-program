#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string filename = "output.bin";  // Name of the binary file to write to
    ofstream outputFile(filename, ios::binary);  // Open file in binary mode

    if (!outputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    // Example binary data (e.g., an array of integers)
    vector<int> data = {100, 200, 300, 400, 500};

    // Write the binary data to the file
    outputFile.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(int));

    if (!outputFile) {
        cerr << "Error: Failed to write the binary data to the file." << endl;
        return 1;
    }

    outputFile.close();  // Close the file
    cout << "Binary data written to " << filename << " successfully." << endl;

    return 0;
}
