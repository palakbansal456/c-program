#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("numbers.txt");  // Open the file for reading

    if (!inputFile) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    int number;
    cout << "Integers read from file:\n";
    
    while (inputFile >> number) {
        cout << number << " ";
    }

    inputFile.close();  // Always close the file when done
    cout << endl;

    return 0;
}
