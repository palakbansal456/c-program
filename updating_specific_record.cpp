#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define a structure to represent a simple record
struct Employee {
    int id;
    char name[50];
    double salary;
};

// Function to write an employee record at a specific position in the binary file
void writeEmployeeAtPosition(fstream& file, const Employee& emp, int position) {
    file.seekp(position * sizeof(Employee), ios::beg); // Move the pointer to the specific position
    file.write(reinterpret_cast<const char*>(&emp), sizeof(Employee)); // Write the data to the file
}

// Function to read an employee record from a specific position in the binary file
void readEmployeeAtPosition(fstream& file, Employee& emp, int position) {
    file.seekg(position * sizeof(Employee), ios::beg); // Move the pointer to the specific position
    file.read(reinterpret_cast<char*>(&emp), sizeof(Employee)); // Read the data from the file
}

// Function to update an employee record by modifying the salary
void updateEmployeeSalary(fstream& file, int position, double newSalary) {
    Employee emp;
    // Read the employee record at the given position
    readEmployeeAtPosition(file, emp, position);
    
    // Update the salary
    emp.salary = newSalary;
    
    // Write the updated record back to the file at the same position
    writeEmployeeAtPosition(file, emp, position);
}

int main() {
    string filename = "employees.dat";

    // Create or open the binary file in read/write mode
    fstream file(filename, ios::in | ios::out | ios::binary | ios::trunc);
    if (!file) {
        cerr << "Error: Could not open the file for random access." << endl;
        return 1;
    }

    // --- Writing some sample employee records ---
    Employee emp1 = {1, "Alice", 50000.0};
    Employee emp2 = {2, "Bob", 60000.0};
    Employee emp3 = {3, "Charlie", 70000.0};

    // Write employee records to positions 0, 1, and 2
    writeEmployeeAtPosition(file, emp1, 0);  // Write at position 0
    writeEmployeeAtPosition(file, emp2, 1);  // Write at position 1
    writeEmployeeAtPosition(file, emp3, 2);  // Write at position 2

    cout << "Sample employee records written to the file." << endl;

    // --- Update specific employee record ---
    int positionToUpdate = 1;  // Let's say we want to update Bob's salary (position 1)
    double newSalary = 65000.0;

    // Update the salary of the employee at position 1
    updateEmployeeSalary(file, positionToUpdate, newSalary);
    cout << "\nUpdated employee salary at position " << positionToUpdate << " to " << newSalary << endl;

    // --- Display all records after update ---
    Employee readEmp;
    cout << "\nDisplaying all employee records after update:" << endl;
    for (int i = 0; i < 3; ++i) {
        readEmployeeAtPosition(file, readEmp, i);
        cout << "Position " << i << ": ID = " << readEmp.id << ", Name = " << readEmp.name << ", Salary = " << readEmp.salary << endl;
    }

    // Close the file
    file.close();

    return 0;
}
