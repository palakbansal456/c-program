#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void readCSVFile(const std::string& filePath) {
    std::ifstream file(filePath);  // Open the CSV file for reading
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    std::string line;
    // Read the header (optional)
    if (std::getline(file, line)) {
        std::cout << "Header: " << line << std::endl;
    }

    // Read the rest of the lines
    while (std::getline(file, line)) {
        std::stringstream ss(line);  // Use a stringstream to split by commas
        std::string cell;
        std::vector<std::string> row;

        // Split the line by commas
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Process the row (here, we simply print the values)
        std::cout << "Row: ";
        for (const auto& field : row) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }

    file.close();  // Close the file
}

int main() {
    std::string filePath = "example.csv";  // Specify the path to your CSV file
    readCSVFile(filePath);  // Read and process the CSV file

    return 0;
}
