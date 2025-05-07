#include <iostream>
using namespace std;

// Function template for linear search
template <typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i; // return index if found
    }
    return -1; // return -1 if not found
}

int main() {
    // Test with int
    int intArr[] = {10, 20, 30, 40, 50};
    int intKey = 30;
    int intIndex = linearSearch(intArr, 5, intKey);
    cout << "Integer key " << intKey << " found at index: " << intIndex << endl;

    // Test with double
    double dblArr[] = {1.1, 2.2, 3.3, 4.4};
    double dblKey = 3.3;
    int dblIndex = linearSearch(dblArr, 4, dblKey);
    cout << "Double key " << dblKey << " found at index: " << dblIndex << endl;

    // Test with char
    char charArr[] = {'a', 'e', 'i', 'o', 'u'};
    char charKey = 'o';
    int charIndex = linearSearch(charArr, 5, charKey);
    cout << "Char key '" << charKey << "' found at index: " << charIndex << endl;

    return 0;
}
