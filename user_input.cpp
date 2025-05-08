#include <iostream>
#include <fstream>   // For file output
#include <string>
using namespace std;

int main() {
    string filename = "output.txt";
    ofstream outputFile(filename);  // Create and open file for writing

    if (!outputFile) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return 1;
    }

    cout << "Enter text to write to the file (type 'exit' to stop):" << endl;
    string line;

    while (true) {
        getline(cin, line);
        if (line == "exit") break;
        outputFile << line << endl;  // Write line to file
    }

    outputFile.close();  // Close the file
    cout << "Data written to " << filename << " successfully." << endl;

    return 0;
}
