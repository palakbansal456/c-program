#include <iostream>
using namespace std;

// Function to swap values using pointers
void swapValues(int* a, int* b) {
    int temp = *a;  // store value pointed by a
    *a = *b;        // assign value of b to a
    *b = temp;      // assign stored value to b
}

int main() {
    int x = 5, y = 10;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    // Call function with addresses
    swapValues(&x, &y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
