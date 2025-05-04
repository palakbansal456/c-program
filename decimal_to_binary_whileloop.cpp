#include <iostream>
using namespace std;

int main() {
    int decimal, binary = 0, remainder, place = 1;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    int original = decimal;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * place;
        place *= 10;
        decimal /= 2;
    }

    cout << "Binary equivalent of " << original << " is: " << binary << endl;

    return 0;
}
