#include <iostream>
#include <fstream>
using namespace std;

class FileHandler {
private:
    ofstream file;

public:
    // Constructor: opens the file
    FileHandler(const string& filename) {
        file.open(filename);
        if (file.is_open()) {
            cout << "File opened successfully.\n";
            file << "Writing some sample text to the file.\n";
        } else {
            cout << "Failed to open the file.\n";
        }
    }

    // Destructor: closes the file
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            cout << "File closed in destructor.\n";
        }
    }
};

int main() {
    {
        FileHandler handler("example.txt"); // File opened here
    } // FileHandler object goes out of scope, destructor called here

    return 0;
}
