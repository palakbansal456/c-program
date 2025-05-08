#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define a complex data structure (structure)
struct Employee {
    int id;
    string name;
    double salary;

    // A function to display employee data
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }
};

int main() {
    string filename = "employee_data.bin";

    // Create an example employee object
    Employee emp1 = {101, "John Doe", 75000.50};

    // Writing the employee data to a binary file
    ofstream outputFile(filename, ios::binary);
    if (!outputFile) {
        cerr << "Error: Could not open the file " << filename << " for writing." << endl;
        return 1;
    }

    // Write the employee object to the file (struct data)
    outputFile.write(reinterpret_cast<const char*>(&emp1), sizeof(Employee));

    if (!outputFile) {
        cerr << "Error: Failed to write the employee data to the file." << endl;
        return 1;
    }

    outputFile.close();  // Close the file after writing
    cout << "Employee data written to " << filename << " successfully." << endl;

    // Reading the employee data back from the binary file
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error: Could not open the file " << filename << " for reading." << endl;
        return 1;
    }

    Employee emp2;
    // Read the employee object from the file
    inputFile.read(reinterpret_cast<char*>(&emp2), sizeof(Employee));

    if (!inputFile) {
        cerr << "Error: Failed to read the employee data from the file." << endl;
        return 1;
    }

    inputFile.close();  // Close the file after reading
    cout << "Employee data read from the file:" << endl;
    emp2.display();  // Display the employee data read from the file

    return 0;
}
