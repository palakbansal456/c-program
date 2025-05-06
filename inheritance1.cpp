#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    void setPersonInfo(string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};

// Derived class
class Employee : public Person {
private:
    int employeeID;
    string position;

public:
    void setEmployeeInfo(int id, string pos) {
        employeeID = id;
        position = pos;
    }

    void displayEmployeeInfo() {
        displayPersonInfo(); // call base class function
        cout << "Employee ID: " << employeeID << endl;
        cout << "Position   : " << position << endl;
    }
};

int main() {
    Employee e1;

    e1.setPersonInfo("Alice", 30);
    e1.setEmployeeInfo(1001, "Software Engineer");

    e1.displayEmployeeInfo();

    return 0;
}
