#include <iostream>
using namespace std;

int main() {
    int number, originalNumber, reversed = 0, remainder;

    cout << "Enter a number: ";
    cin >> number;

    originalNumber = number; 

    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    if (originalNumber == reversed) {
        cout << originalNumber << " is a palindrome." << endl;
    } else {
        cout << originalNumber << " is not a palindrome." << endl;
    }

    return 0;
}
