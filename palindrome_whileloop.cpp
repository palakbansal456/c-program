#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0, remainder, original;

    cout << "Enter a number: ";
    cin >> number;

    original = number;

    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    if (original == reversed) {
        cout << original << " is a palindrome." << endl;
    } else {
        cout << original << " is not a palindrome." << endl;
    }

    return 0;
}
