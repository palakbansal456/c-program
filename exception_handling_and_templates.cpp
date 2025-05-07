#include <iostream>
#include <stdexcept>  // For exception handling
using namespace std;

// Template class for SafeArray
template <typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    // Constructor to initialize array of a given size
    SafeArray(int size) : size(size) {
        if (size <= 0) {
            throw invalid_argument("Array size must be greater than 0.");
        }
        arr = new T[size];  // Dynamically allocate array
    }

    // Destructor to release allocated memory
    ~SafeArray() {
        delete[] arr;
    }

    // Function to set element at a given index
    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }
        arr[index] = value;
    }

    // Function to get element at a given index
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }
        return arr[index];
    }

    // Function to get the size of the array
    int getSize() const {
        return size;
    }
};

// Main function to test the SafeArray class
int main() {
    try {
        // Create a SafeArray of integers with size 5
        SafeArray<int> arr(5);

        // Set values in the array
        arr.set(0, 10);
        arr.set(1, 20);
        arr.set(2, 30);
        arr.set(3, 40);
        arr.set(4, 50);

        // Display values from the array
        cout << "Array values: ";
        for (int i = 0; i < arr.getSize(); ++i) {
            cout << arr.get(i) << " ";
        }
        cout << endl;

        // Try accessing an invalid index
        cout << "Accessing invalid index: ";
        cout << arr.get(5) << endl;  // This will throw an exception
    }
    catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        // Create an array with invalid size (0)
        SafeArray<int> invalidArray(0);
    }
    catch (const invalid_argument& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
