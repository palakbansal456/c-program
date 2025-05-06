#include <iostream>
using namespace std;

// Base class
class Parent {
public:
    void showParent() {
        cout << "This is the Parent class." << endl;
    }
};

// Another base class
class Child1 {
public:
    void showChild1() {
        cout << "This is Child1 class." << endl;
    }
};

// Another base class
class Child2 {
public:
    void showChild2() {
        cout << "This is Child2 class." << endl;
    }
};

// Derived class with multiple inheritance
class GrandChild : public Parent, public Child1, public Child2 {
public:
    void showGrandChild() {
        cout << "This is the GrandChild class (derived from Parent, Child1, and Child2)." << endl;
    }
};

int main() {
    GrandChild obj;

    obj.showParent();
    obj.showChild1();
    obj.showChild2();
    obj.showGrandChild();

    return 0;
}
