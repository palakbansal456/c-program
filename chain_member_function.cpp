#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string city;

public:
    // Set name and return current object
    Person& setName(const string& n) {
        name = n;
        return *this;
    }

    // Set age and return current object
    Person& setAge(int a) {
        age = a;
        return *this;
    }

    // Set city and return current object
    Person& setCity(const string& c) {
        city = c;
        return *this;
    }

    // Display information
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", City: " << city << endl;
    }
};

int main() {
    Person p;

    // Chaining member function calls using `this` pointer
    p.setName("John Doe")
     .setAge(28)
     .setCity("New York")
     .display();

    return 0;
}
