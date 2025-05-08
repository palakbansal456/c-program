#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Define a structure to represent a simple record
struct Employee {
    int id;
    char name[50];
    double salary;
};

// Function to read an employee record from a specific position in the binary file
void readEmployeeAtPosition(fstream& file, Employee& emp, int position) {
    file.seekg(position * sizeof(Employee), ios::beg); // Move the pointer to the specific position
    file.read(reinterpret_cast<char*>(&emp), sizeof(Employee)); // Read the data from the file
}

// Function to display employee details
void displayEmployee(const Employee& emp) {
    cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: " << emp.salary << endl;
}

int main() {
    string filename = "employees.dat";

    // Open the binary file in read mode
    fstream file(filename, ios::in | ios::binary);
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    // Determine the number of records in the file
    file.seekg(0, ios::end);  // Move to the end of the file
    int fileSize = file.tellg(); // Get the total file size in bytes
    int recordCount = fileSize / sizeof(Employee);  // Calculate number of records

    if (recordCount == 0) {
        cout << "The file is empty!" << endl;
        file.close();
        return 0;
    }

    // Read and display the records in reverse order
    cout << "\nDisplaying employee records in reverse order:\n";
    Employee emp;
    for (int i = recordCount - 1; i >= 0; --i) {
        readEmployeeAtPosition(file, emp, i); // Read the record from the current position
        displayEmployee(emp); // Display the employee record
    }

    // Close the file
    file.close();
    return 0;
}
