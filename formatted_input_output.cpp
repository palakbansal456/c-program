#include <iostream>
#include <iomanip>  // For setw, fixed, setprecision
#include <string>
using namespace std;

int main() {
    const int numRows = 3;

    string name[numRows] = {"Alice", "Bob", "Charlie"};
    int age[numRows] = {28, 34, 22};
    double salary[numRows] = {52000.50, 61000.75, 48000.00};

    // Table Header
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Age"
         << right << setw(15) << "Salary ($)" << endl;
    cout << string(40, '-') << endl;

    // Table Rows
    for (int i = 0; i < numRows; ++i) {
        cout << left << setw(15) << name[i]
             << right << setw(10) << age[i]
             << right << setw(15) << fixed << setprecision(2) << salary[i] << endl;
    }

    return 0;
}
