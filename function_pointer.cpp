#include <iostream>
using namespace std;

// Define a callback function type (Function pointer type)
typedef void (*Callback)(int);

// Function that processes data and calls a callback function
void processData(int data, Callback callback) {
    cout << "Processing data: " << data << endl;
    callback(data); // Call the callback function with data
}

// Callback function 1: Print the square of the number
void printSquare(int number) {
    cout << "Square of " << number << " is " << number * number << endl;
}

// Callback function 2: Print the double of the number
void printDouble(int number) {
    cout << "Double of " << number << " is " << number * 2 << endl;
}

int main() {
    int value = 5;
    
    // Using processData with different callback functions
    cout << "Using printSquare callback:" << endl;
    processData(value, printSquare);

    cout << "\nUsing printDouble callback:" << endl;
    processData(value, printDouble);

    return 0;
}
