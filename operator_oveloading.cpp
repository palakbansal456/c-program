#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Polynomial {
private:
    vector<int> coeff; // Stores the coefficients of the polynomial

public:
    // Constructor to initialize the polynomial with a given degree and coefficients
    Polynomial(int degree) {
        coeff.resize(degree + 1, 0); // Resize the vector to store coefficients
    }

    // Function to set the coefficient for a specific degree
    void setCoeff(int degree, int value) {
        if (degree >= 0 && degree < coeff.size()) {
            coeff[degree] = value;
        }
    }

    // Function to get the coefficient of a specific degree
    int getCoeff(int degree) const {
        if (degree >= 0 && degree < coeff.size()) {
            return coeff[degree];
        }
        return 0;
    }

    // Overload the + operator to add two polynomials
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(coeff.size(), other.coeff.size()) - 1;
        Polynomial result(maxDegree); // Create a result polynomial

        for (int i = 0; i <= maxDegree; ++i) {
            result.setCoeff(i, this->getCoeff(i) + other.getCoeff(i));
        }

        return result;
    }

    // Overload the * operator to multiply two polynomials
    Polynomial operator*(const Polynomial& other) const {
        int resultDegree = coeff.size() + other.coeff.size() - 2;
        Polynomial result(resultDegree);

        // Multiply each term of the first polynomial with each term of the second polynomial
        for (int i = 0; i < coeff.size(); ++i) {
            for (int j = 0; j < other.coeff.size(); ++j) {
                result.setCoeff(i + j, result.getCoeff(i + j) + this->getCoeff(i) * other.getCoeff(j));
            }
        }

        return result;
    }

    // Function to display the polynomial
    void display() const {
        bool firstTerm = true;
        for (int i = coeff.size() - 1; i >= 0; --i) {
            if (coeff[i] != 0) {
                if (!firstTerm && coeff[i] > 0) cout << " + ";
                if (coeff[i] < 0) cout << " - ";
                if (abs(coeff[i]) != 1 || i == 0) {
                    cout << abs(coeff[i]);
                }
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
                firstTerm = false;
            }
        }
        cout << endl;
    }
};

int main() {
    // Polynomial 1: 3x^2 + 2x + 1
    Polynomial p1(2);  // Degree 2 polynomial
    p1.setCoeff(2, 3);
    p1.setCoeff(1, 2);
    p1.setCoeff(0, 1);

    // Polynomial 2: x^2 + x + 1
    Polynomial p2(2);  // Degree 2 polynomial
    p2.setCoeff(2, 1);
    p2.setCoeff(1, 1);
    p2.setCoeff(0, 1);

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    // Adding two polynomials
    Polynomial sum = p1 + p2;
    cout << "Sum of Polynomials: ";
    sum.display();

    // Multiplying two polynomials
    Polynomial product = p1 * p2;
    cout << "Product of Polynomials: ";
    product.display();

    return 0;
}
