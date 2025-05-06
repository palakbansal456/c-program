#include <iostream>
using namespace std;

// Overloaded function to find the maximum of two numbers
int maximum(int a, int b) {
    return (a > b) ? a : b;  // Return the greater of the two numbers
}

// Overloaded function to find the maximum of three numbers
int maximum(int a, int b, int c) {
    return (a > b && a > c) ? a : (b > c ? b : c);  // Return the greatest of the three numbers
}

int main() {
    int num1, num2, num3;

    // Input for two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Maximum of two numbers: " << maximum(num1, num2) << endl;

    // Input for three numbers
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Maximum of three numbers: " << maximum(num1, num2, num3) << endl;

    return 0;
}
