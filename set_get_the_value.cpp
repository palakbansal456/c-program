#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Setter for age
    void setAge(int a) {
        age = a;
    }

    // Getter for age
    int getAge() {
        return age;
    }
};

int main() {
    Person p;

    // Set values
    p.setName("Alice");
    p.setAge(25);

    // Get and print values
    cout << "Name: " << p.getName() << endl;
    cout << "Age: " << p.getAge() << endl;

    return 0;
}
