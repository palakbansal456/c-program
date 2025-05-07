#include <iostream>
#include <iomanip>   // For fixed, setprecision, setw
#include <string>    // For string
using namespace std;

int main() {
    string name;
    int age;
    double salary;

    // Input user details
    cout << "Enter your name: ";
    getline(cin, name);  // To allow full name with spaces

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your salary: ";
    cin >> salary;

    // Display the details using formatted output
    cout << "\n--- User Information ---\n";
    cout << left << setw(10) << "Name:" << name << endl;
    cout << left << setw(10) << "Age:" << age << endl;
    cout << left << setw(10) << "Salary: $" << fixed << setprecision(2) << salary << endl;

    return 0;
}
