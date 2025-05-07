#include <iostream>
using namespace std;

// Base class: Appliance
class Appliance {
public:
    // Virtual function to display functionality
    virtual void showFunctionality() const {
        cout << "Generic appliance functionality." << endl;
    }

    virtual ~Appliance() {}
};

// Derived class: WashingMachine
class WashingMachine : public Appliance {
public:
    void showFunctionality() const override {
        cout << "WashingMachine: Washes and rinses clothes." << endl;
    }
};

// Derived class: Refrigerator
class Refrigerator : public Appliance {
public:
    void showFunctionality() const override {
        cout << "Refrigerator: Keeps food cold and fresh." << endl;
    }
};

// Derived class: Microwave
class Microwave : public Appliance {
public:
    void showFunctionality() const override {
        cout << "Microwave: Heats and cooks food quickly." << endl;
    }
};

int main() {
    // Base class pointers to derived objects
    Appliance* a1 = new WashingMachine();
    Appliance* a2 = new Refrigerator();
    Appliance* a3 = new Microwave();

    // Display functionality using polymorphism
    a1->showFunctionality();
    a2->showFunctionality();
    a3->showFunctionality();

    // Clean up
    delete a1;
    delete a2;
    delete a3;

    return 0;
}
