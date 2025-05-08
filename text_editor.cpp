#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void createOrOpenFile(std::ofstream& outFile, std::ifstream& inFile, const std::string& filename) {
    // Check if the file exists
    inFile.open(filename);
    
    if (inFile.is_open()) {
        std::cout << "File opened successfully.\n";
        // Read and display the content of the file
        std::cout << "Current content of the file:\n";
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    } else {
        std::cout << "File does not exist or could not be opened. Creating a new file.\n";
    }

    // Open the file for writing
    outFile.open(filename, std::ios::app); // Open for appending, create if doesn't exist
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        exit(1);
    }
}

void writeToFile(std::ofstream& outFile) {
    std::cin.ignore();  // To clear the input buffer
    std::string line;
    
    std::cout << "Enter text to write to the file (type 'exit' to stop writing):\n";
    
    while (true) {
        std::getline(std::cin, line);
        
        if (line == "exit") {
            break;
        }
        
        outFile << line << "\n";  // Write each line to the file
    }
}

void readFileContents(std::ifstream& inFile, const std::string& filename) {
    inFile.open(filename);
    
    if (inFile.is_open()) {
        std::cout << "Contents of the file:\n";
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    } else {
        std::cout << "File could not be opened to read.\n";
    }
}

int main() {
    std::string filename;
    std::cout << "Enter the filename to open or create: ";
    std::cin >> filename;

    std::ofstream outFile;
    std::ifstream inFile;

    createOrOpenFile(outFile, inFile, filename); // Open or create the file

    int choice;
    do {
        std::cout << "\nSimple Text Editor\n";
        std::cout << "1. Write to file\n";
        std::cout << "2. Read file contents\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(outFile);  // Write text to the file
                break;
            case 2:
                readFileContents(inFile, filename);  // Read and display file contents
                break;
            case 3:
                std::cout << "Exiting the text editor.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    outFile.close(); // Close the output file stream
    return 0;
}
