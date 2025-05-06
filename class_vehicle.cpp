#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    virtual void displayInfo() {
        cout << "This is a vehicle." << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
public:
    void displayInfo() override {
        cout << "This is a car." << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
public:
    void displayInfo() override {
        cout << "This is a bike." << endl;
    }
};

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Bike();

    v1->displayInfo();
    v2->displayInfo();

    delete v1;
    delete v2;

    return 0;
}
