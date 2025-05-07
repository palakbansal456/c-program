#include <iostream>
using namespace std;

// Abstract base class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}

    // Pure virtual functions
    virtual double calculateSalary() const = 0;
    virtual void displayDetails() const = 0;

    virtual ~Employee() {}
};

// Derived class: Manager
class Manager : public Employee {
private:
    double baseSalary;
    double bonus;

public:
    Manager(string n, int i, double base, double b)
        : Employee(n, i), baseSalary(base), bonus(b) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void displayDetails() const override {
        cout << "Manager Name: " << name << ", ID: " << id
             << ", Salary: $" << calculateSalary() << endl;
    }
};

// Derived class: Engineer
class Engineer : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Engineer(string n, int i, double rate, int hours)
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayDetails() const override {
        cout << "Engineer Name: " << name << ", ID: " << id
             << ", Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    // Create Employee pointers to derived class objects
    Employee* e1 = new Manager("Alice", 101, 5000.0, 1200.0);
    Employee* e2 = new Engineer("Bob", 102, 50.0, 160);

    // Display details using polymorphism
    e1->displayDetails();
    e2->displayDetails();

    // Clean up
    delete e1;
    delete e2;

    return 0;
}
