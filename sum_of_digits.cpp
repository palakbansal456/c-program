#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter a numbers: ";
    cin >> num;

    int originalNumber = num; 

    while (num != 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }

    cout << "The sum of the digits of " << originalNumber << " is: " << sum << endl;

    return 0;
}
