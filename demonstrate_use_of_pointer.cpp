#include <iostream>
using namespace std;

// Define the Person class
class Person {
public:
    string name;
    int age;

    // Member function that takes a pointer to another Person object
    void compareAge(Person* other) {
        if (this->age > other->age) {
            cout << name << " is older than " << other->name << "." << endl;
        } else if (this->age < other->age) {
            cout << name << " is younger than " << other->name << "." << endl;
        } else {
            cout << name << " and " << other->name << " are the same age." << endl;
        }
    }
};

int main() {
    // Create two Person objects
    Person person1, person2;

    // Set details
    person1.name = "Alice";
    person1.age = 25;

    person2.name = "Bob";
    person2.age = 30;

    // Use pointer to object in member function
    person1.compareAge(&person2);  // person1 compares with person2

    return 0;
}
