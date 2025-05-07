#include <iostream>
using namespace std;

const int MAX = 100;

template <typename T>
class Stack {
private:
    T arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(T value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display() const {
        if (top < 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    intStack.pop();
    intStack.display();

    cout << "\n";

    Stack<string> strStack;
    strStack.push("Alice");
    strStack.push("Bob");
    strStack.display();
    strStack.pop();
    strStack.display();

    return 0;
}
