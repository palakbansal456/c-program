#include <iostream>
using namespace std;

int maxOfThree(int a, int b, int c);

int main() {
    int num1, num2, num3;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    int maxNum = maxOfThree(num1, num2, num3);
    cout << "The maximum of the three numbers is: " << maxNum << endl;

    return 0;
}

int maxOfThree(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}
