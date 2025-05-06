#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor to initialize complex number
    Complex(float r, float i) : real(r), imag(i) {}

    // Overloading the + operator to add two complex numbers
    Complex operator+(const Complex& other) {
        // Add real and imaginary parts separately
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display the complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Create two complex numbers
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    // Add the two complex numbers using overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result
    cout << "Result of addition: ";
    c3.display();

    return 0;
}
