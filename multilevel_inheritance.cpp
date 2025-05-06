#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void showBase() {
        cout << "This is the Base class." << endl;
    }
};

// Intermediate class derived from Base
class Intermediate : public Base {
public:
    void showIntermediate() {
        cout << "This is the Intermediate class." << endl;
    }
};

// Derived class derived from Intermediate
class Derived : public Intermediate {
public:
    void showDerived() {
        cout << "This is the Derived class." << endl;
    }
};

int main() {
    Derived obj;

    obj.showBase();         // inherited from Base
    obj.showIntermediate(); // inherited from Intermediate
    obj.showDerived();      // from Derived

    return 0;
}
