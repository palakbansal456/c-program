#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients; // Vector to store coefficients of the polynomial

public:
    // Constructor to initialize polynomial with a given degree
    Polynomial(int degree) {
        coefficients.resize(degree + 1, 0); // Resizing the vector to hold degree + 1 coefficients
    }

    // Method to set the coefficient of the polynomial for a given degree
    void setCoefficient(int degree, int value) {
        if (degree >= 0 && degree < coefficients.size()) {
            coefficients[degree] = value;
        }
    }

    // Method to display the polynomial
    void display() {
        bool firstTerm = true;
        for (int i = coefficients.size() - 1; i >= 0; i--) {
            if (coefficients[i] != 0) {
                if (!firstTerm && coefficients[i] > 0) {
                    cout << "+";
                }
                cout << coefficients[i];
                if (i > 0) {
                    cout << "x^" << i << " ";
                }
                firstTerm = false;
            }
        }
        cout << endl;
    }

    // Method to add two polynomials
    Polynomial add(const Polynomial &other) {
        int maxDegree = max(coefficients.size(), other.coefficients.size());
        Polynomial result(maxDegree - 1);

        for (int i = 0; i < maxDegree; i++) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result.setCoefficient(i, coeff1 + coeff2);
        }
        return result;
    }

    // Method to multiply two polynomials
    Polynomial multiply(const Polynomial &other) {
        int resultDegree = coefficients.size() + other.coefficients.size() - 2;
        Polynomial result(resultDegree);

        for (int i = 0; i < coefficients.size(); i++) {
            for (int j = 0; j < other.coefficients.size(); j++) {
                int currentCoeff = coefficients[i] * other.coefficients[j];
                int degree = i + j;
                result.setCoefficient(degree, result.coefficients[degree] + currentCoeff);
            }
        }
        return result;
    }
};

int main() {
    // Create two polynomials: P1 = 3x^2 + 2x + 1, and P2 = x^2 + 5x + 6
    Polynomial P1(2); // Degree 2 polynomial
    P1.setCoefficient(2, 3); // 3x^2
    P1.setCoefficient(1, 2); // 2x
    P1.setCoefficient(0, 1); // 1

    Polynomial P2(2); // Degree 2 polynomial
    P2.setCoefficient(2, 1); // x^2
    P2.setCoefficient(1, 5); // 5x
    P2.setCoefficient(0, 6); // 6

    cout << "Polynomial P1: ";
    P1.display();

    cout << "Polynomial P2: ";
    P2.display();

    // Adding P1 and P2
    Polynomial sum = P1.add(P2);
    cout << "P1 + P2: ";
    sum.display();

    // Multiplying P1 and P2
    Polynomial product = P1.multiply(P2);
    cout << "P1 * P2: ";
    product.display();

    return 0;
}
