#include <iostream>
#include <iomanip>  // For using manipulators like setw, setprecision, and fixed
using namespace std;

int main() {
    // Declare variables
    int intValue = 12345;
    double doubleValue = 123.456789;
    float floatValue = 98.7654321;

    // Formatting with setw: Sets the width of the output
    cout << "Formatted output using setw:" << endl;
    cout << "Integer with setw(10): " << setw(10) << intValue << endl;
    cout << "Float with setw(10): " << setw(10) << floatValue << endl;
    cout << "Double with setw(10): " << setw(10) << doubleValue << endl;

    // Formatting with setprecision and fixed: Controls decimal precision
    cout << "\nFormatted output using setprecision and fixed:" << endl;
    cout << fixed << setprecision(2);  // Display 2 decimal places
    cout << "Float with fixed and setprecision(2): " << floatValue << endl;
    cout << "Double with fixed and setprecision(2): " << doubleValue << endl;

    // Using setw for alignment and setprecision for floating-point numbers
    cout << "\nFormatted output using setw and setprecision:" << endl;
    cout << setw(10) << fixed << setprecision(4) << doubleValue << endl;
    cout << setw(10) << fixed << setprecision(3) << floatValue << endl;

    return 0;
}
