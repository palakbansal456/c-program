#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {
        cout << "Base class constructor called." << endl;
    }

    void display() {
        cout << "Base class display function." << endl;
    }
};

// Class A inherits from Base virtually
class A : virtual public Base {
public:
    A() {
        cout << "Class A constructor called." << endl;
    }

    void displayA() {
        cout << "Class A display function." << endl;
    }
};

// Class B inherits from Base virtually
class B : virtual public Base {
public:
    B() {
        cout << "Class B constructor called." << endl;
    }

    void displayB() {
        cout << "Class B display function." << endl;
    }
};

// Class C inherits from both A and B, virtually inheriting Base
class C : public A, public B {
public:
    C() {
        cout << "Class C constructor called." << endl;
    }

    void displayC() {
        cout << "Class C display function." << endl;
    }
};

int main() {
    // Create an object of class C
    C c;

    // Call functions from the derived class and base class
    c.display();  // Calls the Base class function
    c.displayA(); // Calls the A class function
    c.displayB(); // Calls the B class function
    c.displayC(); // Calls the C class function

    return 0;
}
