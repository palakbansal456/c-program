#include <iostream>
using namespace std;

inline int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = sum(num1, num2);

    cout << "Sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
