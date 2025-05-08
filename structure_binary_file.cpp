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

// Function to write a structure to a specific position in the binary file
void writeEmployeeAtPosition(fstream& file, const Employee& emp, int position) {
    file.seekp(position * sizeof(Employee), ios::beg); // Move the pointer to the specific position
    file.write(reinterpret_cast<const char*>(&emp), sizeof(Employee)); // Write the data to the file
}

// Function to read a structure from a specific position in the binary file
void readEmployeeAtPosition(fstream& file, Employee& emp, int position) {
    file.seekg(position * sizeof(Employee), ios::beg); // Move the pointer to the specific position
    file.read(reinterpret_cast<char*>(&emp), sizeof(Employee)); // Read the data from the file
}

int main() {
    string filename = "employees.dat";

    // Create or open the binary file in read/write mode
    fstream file(filename, ios::in | ios::out | ios::binary | ios::trunc);
    if (!file) {
        cerr << "Error: Could not open the file for random access." << endl;
        return 1;
    }

    // --- Writing employee records at specific positions ---
    Employee emp1 = {1, "Alice", 50000.0};
    Employee emp2 = {2, "Bob", 60000.0};
    Employee emp3 = {3, "Charlie", 70000.0};

    cout << "Writing records to the binary file..." << endl;
    
    // Write employee records to positions 0, 1, and 2
    writeEmployeeAtPosition(file, emp1, 0);  // Write at position 0
    writeEmployeeAtPosition(file, emp2, 1);  // Write at position 1
    writeEmployeeAtPosition(file, emp3, 2);  // Write at position 2

    cout << "Records written to the file." << endl;

    // --- Reading employee records from specific positions ---
    Employee readEmp;

    cout << "\nReading records from the binary file..." << endl;

    // Read employee records from positions 0, 1, and 2
    readEmployeeAtPosition(file, readEmp, 0); // Read at position 0
    cout << "Position 0: ID = " << readEmp.id << ", Name = " << readEmp.name << ", Salary = " << readEmp.salary << endl;

    readEmployeeAtPosition(file, readEmp, 1); // Read at position 1
    cout << "Position 1: ID = " << readEmp.id << ", Name = " << readEmp.name << ", Salary = " << readEmp.salary << endl;

    readEmployeeAtPosition(file, readEmp, 2); // Read at position 2
    cout << "Position 2: ID = " << readEmp.id << ", Name = " << readEmp.name << ", Salary = " << readEmp.salary << endl;

    // Close the file
    file.close();

    return 0;
}
