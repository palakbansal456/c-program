#include <iostream>
#include <exception>
#include <vector>
using namespace std;

// Define custom exceptions for Stack Overflow and Stack Underflow
class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow: Cannot push to a full stack!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow: Cannot pop from an empty stack!";
    }
};

// Stack class template
template <typename T>
class Stack {
private:
    vector<T> data;    // Dynamic array to store stack elements
    size_t capacity;   // Maximum capacity of the stack

public:
    // Constructor to initialize stack with a given capacity
    Stack(size_t cap) : capacity(cap) {}

    // Push method to add an element to the stack
    void push(const T& element) {
        if (data.size() >= capacity) {
            throw StackOverflowException(); // Throw exception if the stack is full
        }
        data.push_back(element);
        cout << "Pushed: " << element << endl;
    }

    // Pop method to remove an element from the stack
    T pop() {
        if (data.empty()) {
            throw StackUnderflowException(); // Throw exception if the stack is empty
        }
        T top = data.back();
        data.pop_back();
        cout << "Popped: " << top << endl;
        return top;
    }

    // Peek method to view the top element of the stack
    T peek() const {
        if (data.empty()) {
            throw StackUnderflowException(); // Throw exception if the stack is empty
        }
        return data.back();
    }

    // Method to check if the stack is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Method to get the current size of the stack
    size_t size() const {
        return data.size();
    }

    // Method to get the capacity of the stack
    size_t getCapacity() const {
        return capacity;
    }
};

// Main program to demonstrate the Stack class with exception handling
int main() {
    try {
        // Create a stack with capacity of 3
        Stack<int> stack(3);

        // Push elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Attempt to push into a full stack (this should throw an exception)
        stack.push(40);

    } catch (const StackOverflowException& ex) {
        cout << ex.what() << endl;  // Handle Stack Overflow error
    }

    try {
        // Create another stack with capacity of 2
        Stack<int> stack2(2);

        // Push elements onto the stack
        stack2.push(100);
        stack2.push(200);

        // Pop elements from the stack
        stack2.pop();
        stack2.pop();

        // Attempt to pop from an empty stack (this should throw an exception)
        stack2.pop();

    } catch (const StackUnderflowException& ex) {
        cout << ex.what() << endl;  // Handle Stack Underflow error
    }

    return 0;
}
