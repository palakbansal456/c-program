#include <iostream>
using namespace std;

// Abstract base class
class Device {
public:
    // Pure virtual function
    virtual void turnOn() = 0;

    // Virtual destructor
    virtual ~Device() {}
};

// Derived class: Laptop
class Laptop : public Device {
public:
    void turnOn() override {
        cout << "Laptop is booting up..." << endl;
    }
};

// Derived class: Smartphone
class Smartphone : public Device {
public:
    void turnOn() override {
        cout << "Smartphone is powering on..." << endl;
    }
};

int main() {
    // Base class pointers to derived objects
    Device* d1 = new Laptop();
    Device* d2 = new Smartphone();

    // Call turnOn() using base class pointer (polymorphism)
    d1->turnOn();
    d2->turnOn();

    // Clean up
    delete d1;
    delete d2;

    return 0;
}
