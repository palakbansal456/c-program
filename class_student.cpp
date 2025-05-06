#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    static int totalStudents; // Static member to track number of students

public:
    // Constructor
    Student(string n, int r) {
        name = n;
        rollNumber = r;
        totalStudents++;  // Increment when a new student is created
    }

    // Static function to get total number of students
    static int getTotalStudents() {
        return totalStudents;
    }

    // Function to display student details
    void displayDetails() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

// Definition and initialization of static member
int Student::totalStudents = 0;

int main() {
    Student s1("Alice", 1);
    Student s2("Bob", 2);
    Student s3("Charlie", 3);

    // Display total number of students
    cout << "Total Students Enrolled: " << Student::getTotalStudents() << endl;

    return 0;
}
