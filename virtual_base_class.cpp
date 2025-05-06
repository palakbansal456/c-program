#include <iostream>
using namespace std;

// Virtual base class
class Entity {
public:
    void showEntity() {
        cout << "This is a generic entity." << endl;
    }
};

// Derived from virtual base class
class Person : virtual public Entity {
public:
    void showPerson() {
        cout << "This is a person." << endl;
    }
};

// Derived from virtual base class
class Organization : virtual public Entity {
public:
    void showOrganization() {
        cout << "This is an organization." << endl;
    }
};

// Derived from both Person and Organization
class Member : public Person, public Organization {
public:
    void showMember() {
        cout << "This is a member belonging to both person and organization." << endl;
    }
};

int main() {
    Member m;

    m.showEntity();         // From virtual base class
    m.showPerson();         // From Person class
    m.showOrganization();   // From Organization class
    m.showMember();         // From Member class

    return 0;
}
