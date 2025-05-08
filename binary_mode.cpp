#include <iostream>
#include <fstream>  // For file stream operations

using namespace std;

struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    // File name for demonstration
    string filename = "student_data.bin";

    // --- 1. Write to the file in binary mode ---
    cout << "Writing data to the file in binary mode..." << endl;

    // Create an object of the Student structure
    Student student1 = {1, "John Doe", 85.5f};

    // Open the file in binary write mode
    ofstream outFile(filename, ios::out | ios::binary);

    // Check if the file is opened successfully
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    // Write the student data to the file in binary mode
    outFile.write(reinterpret_cast<char*>(&student1), sizeof(student1));

    // Close the file after writing
    outFile.close();
    cout << "Data written to the file and file closed." << endl;

    // --- 2. Read from the file in binary mode ---
    cout << "\nReading data from the file in binary mode..." << endl;

    // Create an object to hold the read data
    Student student2;

    // Open the file in binary read mode
    ifstream inFile(filename, ios::in | ios::binary);

    // Check if the file is opened successfully
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Read the student data from the file in binary mode
    inFile.read(reinterpret_cast<char*>(&student2), sizeof(student2));

    // Close the file after reading
    inFile.close();

    // Display the data read from the file
    cout << "Data read from the file:" << endl;
    cout << "ID: " << student2.id << endl;
    cout << "Name: " << student2.name << endl;
    cout << "Grade: " << student2.grade << endl;

    return 0;
}
