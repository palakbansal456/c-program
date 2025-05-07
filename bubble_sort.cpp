#include <iostream>
using namespace std;

// Function template for bubble sort
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimization: stop if no swaps occurred in this pass
        if (!swapped) break;
    }
}

// Function to display an array
template <typename T>
void display(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Test the bubbleSort template
int main() {
    // Integer array
    int intArr[] = {5, 2, 9, 1, 5, 6};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Original int array: ";
    display(intArr, intSize);
    bubbleSort(intArr, intSize);
    cout << "Sorted int array:   ";
    display(intArr, intSize);

    // Double array
    double dblArr[] = {3.14, 2.71, 1.41, 1.73};
    int dblSize = sizeof(dblArr) / sizeof(dblArr[0]);
    cout << "\nOriginal double array: ";
    display(dblArr, dblSize);
    bubbleSort(dblArr, dblSize);
    cout << "Sorted double array:   ";
    display(dblArr, dblSize);

    // Char array
    char charArr[] = {'z', 'a', 'x', 'm'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "\nOriginal char array: ";
    display(charArr, charSize);
    bubbleSort(charArr, charSize);
    cout << "Sorted char array:   ";
    display(charArr, charSize);

    return 0;
}
