#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;

    cout << "Enter a number: ";
    cin >> number;

    int original = number; // Save original number for display

    if (number < 0) {
        number = -number;
    }

    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }

    cout << "The sum of the digits of " << original << " is: " << sum << endl;

    return 0;
}
