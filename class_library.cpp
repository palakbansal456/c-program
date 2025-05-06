#include <iostream>
using namespace std;

class Library {
private:
    string privateBook = "Private Book"; // Only accessible inside the class

protected:
    string protectedBook = "Protected Book"; // Accessible in derived class

public:
    string publicBook = "Public Book"; // Accessible anywhere

    void showPrivate() {
        cout << "Accessing private member inside class: " << privateBook << endl;
    }
};

// Derived class to access protected member
class DerivedLibrary : public Library {
public:
    void showProtected() {
        cout << "Accessing protected member in derived class: " << protectedBook << endl;
    }
};

int main() {
    Library lib;
    DerivedLibrary dlib;

    cout << "Accessing public member: " << lib.publicBook << endl;

    lib.showPrivate();

    dlib.showProtected();

    return 0;
}
