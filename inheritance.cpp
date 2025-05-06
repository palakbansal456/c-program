#include <iostream>
#include <string>
using namespace std;

// Base class Person
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

// Derived class Student inheriting from Person
class Student : public Person {
private:
    string studentID;

public:
    // Setter for studentID
    void setStudentID(string id) {
        studentID = id;
    }

    // Getter for studentID
    string getStudentID() {
        return studentID;
    }
};

int main() {
    Student s;

    // Set values for the student object
    s.setName("John");
    s.setAge(20);
    s.setStudentID("S12345");

    // Get and print values
    cout << "Student Name: " << s.getName() << endl;
    cout << "Student Age: " << s.getAge() << endl;
    cout << "Student ID: " << s.getStudentID() << endl;

    return 0;
}
