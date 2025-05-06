#include <iostream>
using namespace std;

class Vector {
private:
    int size;
    int* data;

public:
    // Constructor to initialize vector with given size
    Vector(int s) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = 0; // initialize elements to 0
    }

    // Destructor to release memory
    ~Vector() {
        delete[] data;
    }

    // Overload [] operator to access vector elements
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            // Optionally throw exception or handle error more gracefully
            exit(1);
        }
        return data[index];
    }

    // Function to display vector elements
    void display() {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Vector v(5); // create vector of size 5

    // Assign values using overloaded []
    v[0] = 10;
    v[1] = 20;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;

    // Access and display elements
    cout << "Vector elements: ";
    v.display();

    cout << "Element at index 2: " << v[2] << endl;

    return 0;
}
