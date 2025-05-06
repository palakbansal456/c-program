#include <iostream>
using namespace std;

// Function declarations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Declare an array of function pointers
    int (*operations[3])(int, int) = { add, subtract, multiply };

    int a = 10, b = 5;

    // Call each function using the array of pointers
    cout << "Addition: " << operations[0](a, b) << endl;
    cout << "Subtraction: " << operations[1](a, b) << endl;
    cout << "Multiplication: " << operations[2](a, b) << endl;

    return 0;
}
