#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string position;
    double salary;

public:
    // Constructor to initialize employee attributes
    Employee(string n, string p, double s) {
        name = n;
        position = p;
        salary = s;
    }

    // Method to display employee details
    void displayDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Create an Employee object
    Employee emp1("Alice Johnson", "Software Engineer", 75000);

    // Display employee details
    emp1.displayDetails();

    return 0;
}
