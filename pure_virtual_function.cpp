#include <iostream>
using namespace std;

// Abstract class: Vehicle
class Vehicle {
public:
    // Pure virtual function
    virtual void displayInfo() const = 0;

    // Virtual destructor
    virtual ~Vehicle() {}
};

// Derived class: Car
class Car : public Vehicle {
public:
    void displayInfo() const override {
        cout << "This is a Car." << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
public:
    void displayInfo() const override {
        cout << "This is a Bike." << endl;
    }
};

int main() {
    // We cannot create an instance of Vehicle because it's an abstract class
    // Vehicle v;  // This will give an error.

    // Create instances of Car and Bike
    Vehicle* vehicle1 = new Car();
    Vehicle* vehicle2 = new Bike();

    // Display info using base class pointer
    vehicle1->displayInfo();
    vehicle2->displayInfo();

    // Cleanup
    delete vehicle1;
    delete vehicle2;

    return 0;
}
