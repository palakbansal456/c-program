#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold some sample data (used for reading and writing to file)
struct Record {
    int id;
    char name[50];
    double salary;
};

void writeRecordAtPosition(fstream& file, const Record& record, int position) {
    file.seekp(position * sizeof(Record), ios::beg); // Move the file pointer to the desired position
    file.write(reinterpret_cast<const char*>(&record), sizeof(Record)); // Write the record
}

void readRecordAtPosition(fstream& file, Record& record, int position) {
    file.seekg(position * sizeof(Record), ios::beg); // Move the file pointer to the desired position
    file.read(reinterpret_cast<char*>(&record), sizeof(Record)); // Read the record
}

int main() {
    string filename = "random_access.dat";

    // Create or open the binary file for read/write
    fstream file(filename, ios::in | ios::out | ios::binary | ios::trunc);
    if (!file) {
        cerr << "Error: Could not open the file for random access." << endl;
        return 1;
    }

    // --- 1. Write some records at specific positions ---
    cout << "Writing records at specific positions..." << endl;

    // Create some sample records to write
    Record record1 = {1, "Alice", 50000.0};
    Record record2 = {2, "Bob", 60000.0};
    Record record3 = {3, "Charlie", 70000.0};

    writeRecordAtPosition(file, record1, 0); // Write at position 0
    writeRecordAtPosition(file, record2, 1); // Write at position 1
    writeRecordAtPosition(file, record3, 2); // Write at position 2

    cout << "Records written to the file." << endl;

    // --- 2. Read records from specific positions ---
    cout << "\nReading records from specific positions..." << endl;

    // Read records at positions 0, 1, and 2
    Record readRecord;
    readRecordAtPosition(file, readRecord, 0); // Read at position 0
    cout << "Position 0: ID = " << readRecord.id << ", Name = " << readRecord.name << ", Salary = " << readRecord.salary << endl;

    readRecordAtPosition(file, readRecord, 1); // Read at position 1
    cout << "Position 1: ID = " << readRecord.id << ", Name = " << readRecord.name << ", Salary = " << readRecord.salary << endl;

    readRecordAtPosition(file, readRecord, 2); // Read at position 2
    cout << "Position 2: ID = " << readRecord.id << ", Name = " << readRecord.name << ", Salary = " << readRecord.salary << endl;

    // Close the file after reading and writing
    file.close();

    return 0;
}
