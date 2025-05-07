#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// RAII class to manage file resource
class FileHandler {
private:
    ifstream file;
    string filename;

public:
    FileHandler(const string& fname) : filename(fname) {
        file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("Failed to open file: " + filename);
        }
        cout << "File opened successfully.\n";
    }

    void readFile() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            cout << "File closed (resource released).\n";
        }
    }
};

int main() {
    string fname;
    cout << "Enter filename to read: ";
    cin >> fname;

    try {
        FileHandler fh(fname);  // RAII ensures file is closed even if an exception occurs
        fh.readFile();
    } 
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // No matter what happens above, file will be closed due to destructor of FileHandler

    return 0;
}
