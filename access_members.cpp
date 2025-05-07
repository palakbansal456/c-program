#include <iostream>
using namespace std;

// Define the Student class
class Student {
public:
    string name;
    int age;

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Dynamically create a Student object
    Student* studentPtr = new Student;

    // Access and set members using pointer
    studentPtr->name = "Alice";
    studentPtr->age = 20;

    // Call member function using pointer
    studentPtr->displayInfo();

    // Free the dynamically allocated memory
    delete studentPtr;

    return 0;
}
