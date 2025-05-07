#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    // Virtual function to be overridden
    virtual void displayRole() const {
        cout << "I am an employee." << endl;
    }

    virtual ~Employee() {}
};

// Derived class: Manager
class Manager : public Employee {
public:
    void displayRole() const override {
        cout << "I am a Manager. I manage the team." << endl;
    }
};

// Derived class: Worker
class Worker : public Employee {
public:
    void displayRole() const override {
        cout << "I am a Worker. I do assigned tasks." << endl;
    }
};

// Main function to demonstrate overriding
int main() {
    Employee* e1 = new Manager();
    Employee* e2 = new Worker();

    e1->displayRole();  // Calls Manager's displayRole
    e2->displayRole();  // Calls Worker's displayRole

    // Clean up
    delete e1;
    delete e2;

    return 0;
}
