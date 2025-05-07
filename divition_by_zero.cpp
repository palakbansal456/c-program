#include <iostream>
using namespace std;

double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int a, b;

    cout << "Enter numerator: ";
    cin >> a;
    cout << "Enter denominator: ";
    cin >> b;

    try {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
