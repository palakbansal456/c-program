#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables for different data types
    int intValue;
    float floatValue;
    double doubleValue;
    char charValue;
    string stringValue;

    // Input values for each data type
    cout << "Enter an integer: ";
    cin >> intValue;

    cout << "Enter a float: ";
    cin >> floatValue;

    cout << "Enter a double: ";
    cin >> doubleValue;

    cout << "Enter a character: ";
    cin >> charValue;

    cout << "Enter a string: ";
    cin.ignore();  // Ignore any leftover newline character from previous input
    getline(cin, stringValue);  // Read a full line of text (including spaces)

    // Output the values of the variables
    cout << "\nYou entered the following values:" << endl;
    cout << "Integer: " << intValue << endl;
    cout << "Float: " << floatValue << endl;
    cout << "Double: " << doubleValue << endl;
    cout << "Character: " << charValue << endl;
    cout << "String: " << stringValue << endl;

    return 0;
}
