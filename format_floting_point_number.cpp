#include <iostream>
#include <iomanip>  // For manipulators
using namespace std;

int main() {
    double number = 12345.6789;

    cout << "Original number: " << number << "\n\n";

    cout << "Default (no formatting):\n";
    cout << number << endl;

    cout << "\nFixed-point notation:\n";
    cout << fixed << setprecision(2) << number << endl;
    cout << fixed << setprecision(4) << number << endl;
    cout << fixed << setprecision(6) << number << endl;

    cout << "\nScientific notation:\n";
    cout << scientific << setprecision(2) << number << endl;
    cout << scientific << setprecision(4) << number << endl;
    cout << scientific << setprecision(6) << number << endl;

    return 0;
}
