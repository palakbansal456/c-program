#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char ch;

    // Writing characters to a file using put()
    ofstream outFile("charfile.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "Enter text (press ENTER to finish): ";
    while ((ch = cin.get()) != '\n') {
        outFile.put(ch);  // Write character to file
    }
    outFile.close();

    // Reading characters from the file using get()
    ifstream inFile("charfile.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nContents read from file:" << endl;
    while (inFile.get(ch)) {  // Read character from file
        cout.put(ch);         // Display character to console
    }
    inFile.close();

    cout << "\n\nDone reading and writing characters." << endl;
    return 0;
}
