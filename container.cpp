#include <iostream>
#include <memory>  // For smart pointers
#include <stdexcept>  // For exceptions
using namespace std;

// Template class for a generic container
template <typename T>
class Container {
private:
    unique_ptr<T[]> data;      // Array of elements managed by unique_ptr
    size_t size;               // Number of elements in the container
    size_t capacity;           // Capacity of the container

    // Private helper function to resize the container when it's full
    void resize() {
        // Double the capacity
        capacity = capacity == 0 ? 1 : capacity * 2;
        unique_ptr<T[]> newData = make_unique<T[]>(capacity);
        
        // Copy old elements to the new container
        for (size_t i = 0; i < size; ++i) {
            newData[i] = move(data[i]);
        }

        data = move(newData);
    }

public:
    // Constructor to initialize an empty container
    Container() : size(0), capacity(0), data(nullptr) {}

    // Function to add an element to the container
    void add(const T& value) {
        if (size == capacity) {
            resize();  // Resize the container if it is full
        }
        data[size++] = value;  // Insert the new element
    }

    // Function to retrieve an element by index
    T& get(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of bounds.");
        }
        return data[index];
    }

    // Function to return the size of the container
    size_t getSize() const {
        return size;
    }

    // Function to print all elements in the container
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    // Create a container for integers
    Container<int> intContainer;

    // Add elements to the container
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);

    // Print elements in the container
    cout << "Integer Container: ";
    intContainer.print();

    // Access an element from the container
    try {
        cout << "Element at index 1: " << intContainer.get(1) << endl;
        cout << "Element at index 5: " << intContainer.get(5) << endl;  // This will throw an exception
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Create a container for strings
    Container<string> stringContainer;

    // Add elements to the string container
    stringContainer.add("apple");
    stringContainer.add("banana");
    stringContainer.add("cherry");

    // Print elements in the string container
    cout << "String Container: ";
    stringContainer.print();

    return 0;
}
