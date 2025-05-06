#include <iostream>
using namespace std;

// Inline function definition
inline int square(int n) {
    return n * n;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Square of " << num << " is: " << square(num) << endl;

    return 0;
}
