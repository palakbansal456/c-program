#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

void readFile(const string& filename) {
    ifstream file(filename);

    // Check if the file opened successfully
    if (!file.is_open()) {
        throw runtime_error("Error: Unable to open file '" + filename + "'");
    }

    string line;
    cout << "Contents of the file:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;

    try {
        readFile(filename);
    } 
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
