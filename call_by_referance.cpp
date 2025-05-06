#include <iostream>
using namespace std;

// Function prototype
void incrementByTen(int &num);

int main() {
    int value = 25;

    cout << "Before increment: " << value << endl;

    // Call the function
    incrementByTen(value);

    cout << "After increment: " << value << endl;

    return 0;
}

// Function definition
void incrementByTen(int &num) {
    num += 10;
}
