#include <iostream>
using namespace std;

class Base {
public:
    void showBase() {
        cout << "This is the Base class." << endl;
    }
};

class Derived1 : virtual public Base {
public:
    void showDerived1() {
        cout << "This is Derived1 class." << endl;
    }
};

class Derived2 : virtual public Base {
public:
    void showDerived2() {
        cout << "This is Derived2 class." << endl;
    }
};

class Derived3 : public Derived1, public Derived2 {
public:
    void showDerived3() {
        cout << "This is Derived3 class (Hybrid Inheritance)." << endl;
    }
};

int main() {
    Derived3 obj;
    obj.showBase();        // Inherited via virtual inheritance
    obj.showDerived1();
    obj.showDerived2();
    obj.showDerived3();
    return 0;
}
