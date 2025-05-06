#include <iostream>
using namespace std;

void printArray(int arr[], int size);

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Array elements: ";
    printArray(numbers, length);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
