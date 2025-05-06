#include <iostream>
#include <cmath>
using namespace std;

double compoundInterest(double principal, double rate = 5.0, int time = 2) {
    return principal * pow((1 + rate / 100), time) - principal;
}

int main() {
    double principal;

    cout << "Enter principal amount: ";
    cin >> principal;

    // Call with all default arguments (rate = 5.0%, time = 2 years)
    cout << "Compound Interest (default rate and time): " << compoundInterest(principal) << endl;

    // Call with custom rate
    cout << "Compound Interest (rate = 6.5%, time = 2): " << compoundInterest(principal, 6.5) << endl;

    // Call with custom rate and time
    cout << "Compound Interest (rate = 7.5%, time = 3): " << compoundInterest(principal, 7.5, 3) << endl;

    return 0;
}
