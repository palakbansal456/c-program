#include <iostream>
#include <iomanip>  // For setw
using namespace std;

int main() {
    // Table headers
    cout << setw(15) << "Name"
         << setw(10) << "Age"
         << setw(15) << "City" << endl;

    // Separator line
    cout << setw(15) << "---------------"
         << setw(10) << "----"
         << setw(15) << "---------------" << endl;

    // Data rows
    cout << setw(15) << "Alice"
         << setw(10) << 28
         << setw(15) << "New York" << endl;

    cout << setw(15) << "Bob"
         << setw(10) << 34
         << setw(15) << "Los Angeles" << endl;

    cout << setw(15) << "Charlie"
         << setw(10) << 22
         << setw(15) << "Chicago" << endl;

    return 0;
}
