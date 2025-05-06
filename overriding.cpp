#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    virtual void displayDetails() {
        cout << "This is an employee." << endl;
    }
};

// Derived class
class Manager : public Employee {
public:
    void displayDetails() override {
        cout << "This is a manager." << endl;
    }
};

int main() {
    Employee* empPtr;
    Manager mgr;

    empPtr = &mgr;

    // Function overriding in action
    empPtr->displayDetails();  // Calls Manager's version of displayDetails()

    return 0;
}
