#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string sourceFile = "source.txt";
    string destinationFile = "copy.txt";

    ifstream inputFile(sourceFile);
    ofstream outputFile(destinationFile);

    if (!inputFile) {
        cerr << "Error: Could not open source file." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error: Could not open/create destination file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "File copied successfully from " << sourceFile << " to " << destinationFile << "." << endl;

    return 0;
}
