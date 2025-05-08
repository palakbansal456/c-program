#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "append.txt";
    ofstream outputFile(filename, ios::app);  // Open file in append mode

    if (!outputFile) {
        cerr << "Error: Could not open file " << filename << " for appending." << endl;
        return 1;
    }

    cout << "Enter text to append to the file (type 'exit' to stop):" << endl;
    string line;

    while (true) {
        getline(cin, line);
        if (line == "exit") break;
        outputFile << line << endl;
    }

    outputFile.close();
    cout << "Data successfully appended to " << filename << "." << endl;

    return 0;
}
