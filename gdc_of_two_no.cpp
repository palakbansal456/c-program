#include <iostream>
using namespace std;

int main() {
    int a = 48;
    int b = 18;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "The GCD of given number is: " << a << endl;

    return 0;
}
