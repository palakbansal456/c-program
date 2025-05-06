#include <iostream>
using namespace std;

void doubleArrayElements(int arr[], int size);

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original array: ";
    for (int i = 0; i < length; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    doubleArrayElements(numbers, length);

    cout << "Modified array: ";
    for (int i = 0; i < length; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}

void doubleArrayElements(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;  // Modify each element (e.g., double it)
    }
}
