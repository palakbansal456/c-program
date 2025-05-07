#include <iostream>
using namespace std;

int main() {
    int size;

    // Ask user for array size
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Initialize the array using pointers
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);  // same as arr[i]
    }

    // Display the array
    cout << "You entered: ";
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
