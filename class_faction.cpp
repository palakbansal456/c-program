#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Friend function to overload >> operator (input)
    friend istream& operator>>(istream& in, Fraction& f) {
        cout << "Enter numerator: ";
        in >> f.numerator;
        cout << "Enter denominator: ";
        in >> f.denominator;

        // Avoid division by zero
        if (f.denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1.\n";
            f.denominator = 1;
        }
        return in;
    }

    // Friend function to overload << operator (output)
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f1;

    // Use overloaded >> to input the fraction
    cin >> f1;

    // Use overloaded << to display the fraction
    cout << "The entered fraction is: " << f1 << endl;

    return 0;
}
