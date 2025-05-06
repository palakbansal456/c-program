#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void showBase() {
        cout << "This is the Base class." << endl;
    }
};

// Derived class 1
class Derived1 : public Base {
public:
    void showDerived1() {
        cout << "This is Derived1 class." << endl;
    }
};

// Derived class 2
class Derived2 : public Base {
public:
    void showDerived2() {
        cout << "This is Derived2 class." << endl;
    }
};

// Derived class 3
class Derived3 : public Base {
public:
    void showDerived3() {
        cout << "This is Derived3 class." << endl;
    }
};

int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    cout << "Derived1 object:" << endl;
    d1.showBase();
    d1.showDerived1();

    cout << "\nDerived2 object:" << endl;
    d2.showBase();
    d2.showDerived2();

    cout << "\nDerived3 object:" << endl;
    d3.showBase();
    d3.showDerived3();

    return 0;
}
