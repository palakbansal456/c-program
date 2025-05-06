#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate power with a default exponent of 2
double power(double base, int exponent = 2) {
    return pow(base, exponent);
}

int main() {
    double num;

    cout << "Enter a number: ";
    cin >> num;

    // Using default exponent (2)
    cout << "Square of " << num << " is: " << power(num) << endl;

    // Using custom exponent (3)
    cout << "Cube of " << num << " is: " << power(num, 3) << endl;

    return 0;
}
