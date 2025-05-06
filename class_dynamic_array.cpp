#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor: dynamically allocate memory
    DynamicArray(int s) {
        size = s;
        arr = new int[size]; // allocate memory
        for (int i = 0; i < size; ++i)
            arr[i] = i + 1; // initialize array
        cout << "Dynamic array of size " << size << " created.\n";
    }

    // Function to display array elements
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Destructor: deallocate memory
    ~DynamicArray() {
        delete[] arr; // free allocated memory
        cout << "Dynamic array memory deallocated.\n";
    }
};

int main() {
    {
        DynamicArray myArray(5);
        myArray.display();
    } // Destructor called automatically here

    return 0;
}
