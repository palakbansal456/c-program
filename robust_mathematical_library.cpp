#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception class for division by zero
class DivisionByZeroException : public runtime_error {
public:
    DivisionByZeroException() : runtime_error("Error: Division by zero is not allowed.") {}
};

// Function templates for basic arithmetic operations

// Addition
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Subtraction
template <typename T>
T subtract(T a, T b) {
    return a - b;
}

// Multiplication
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Division with exception handling
template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

// Main function to test the library
int main() {
    try {
        double x = 10.5, y = 0.0; // Test with zero for division
        cout << "Addition: " << add(x, y) << endl;
        cout << "Subtraction: " << subtract(x, y) << endl;
        cout << "Multiplication: " << multiply(x, y) << endl;
        cout << "Division: " << divide(x, y) << endl; // This will throw an exception
    }
    catch (const DivisionByZeroException& e) {
        cout << e.what() << endl; // Catch and display division by zero error
    }
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    try {
        int a = 20, b = 5;
        cout << "Addition: " << add(a, b) << endl;
        cout << "Subtraction: " << subtract(a, b) << endl;
        cout << "Multiplication: " << multiply(a, b) << endl;
        cout << "Division: " << divide(a, b) << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
