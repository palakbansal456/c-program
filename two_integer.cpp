#include <iostream>
using namespace std;

int multiply(int a, int b);

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int product = multiply(num1, num2);
    cout << "Product: " << product << endl;

    return 0;
}

int multiply(int a, int b) {
    return a * b;
}
