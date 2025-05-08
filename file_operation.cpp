#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void openFileForReading(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::ios_base::failure("Error: Could not open file for reading.");
    }

    std::cout << "File opened successfully for reading.\n";
    // Simulate reading file content (for demonstration purposes)
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    file.close();
}

void openFileForWriting(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::ios_base::failure("Error: Could not open file for writing.");
    }

    std::cout << "File opened successfully for writing.\n";
    // Write some content to the file
    file << "This is a sample text written to the file.\n";
    file << "Writing more content...\n";

    file.close();
}

int main() {
    std::string filename;
    
    // Get the filename from the user
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    try {
        // Attempt to open the file for reading
        openFileForReading(filename);
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Attempt to open the file for writing
        openFileForWriting(filename);
    } catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
