#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an array
    int numbers[5] = {10, 20, 30, 40, 50};

    // Declare a pointer and point it to the first element of the array
    int* ptr = numbers;

    cout << "Accessing array elements using pointer arithmetic:" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "Element " << i << " = " << *(ptr + i) << endl;
    }

    return 0;
}
