#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Function to compress a file using Run-Length Encoding (RLE)
void compressFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file for compression." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file for writing." << std::endl;
        return;
    }

    char currentChar;
    char prevChar = '\0';
    int count = 1;

    while (inputFile.get(currentChar)) {
        if (currentChar == prevChar) {
            count++;
        } else {
            if (prevChar != '\0') {
                outputFile << count << prevChar;  // Write the count and the previous character
            }
            prevChar = currentChar;
            count = 1;
        }
    }
    if (prevChar != '\0') {
        outputFile << count << prevChar;  // Write the last character and count
    }

    std::cout << "File compression successful." << std::endl;

    inputFile.close();
    outputFile.close();
}

// Function to decompress a file using Run-Length Encoding (RLE)
void decompressFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file for decompression." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file for writing." << std::endl;
        return;
    }

    std::string countStr;
    while (inputFile.get(countStr[0])) {
        if (isdigit(countStr[0])) {
            countStr = countStr[0];  // Start building the number
            while (inputFile.get(countStr[0]) && isdigit(countStr[0])) {
                countStr += countStr[0];
            }
            int count = std::stoi(countStr);  // Convert to an integer
            char character;
            inputFile.get(character);  // Get the character after the count
            for (int i = 0; i < count; ++i) {
                outputFile.put(character);  // Write the character 'count' times
            }
        }
    }

    std::cout << "File decompression successful." << std::endl;

    inputFile.close();
    outputFile.close();
}

int main() {
    int choice;
    std::string inputFilename, outputFilename;

    std::cout << "Simple Text File Compression and Decompression Program" << std::endl;
    std::cout << "1. Compress a file" << std::endl;
    std::cout << "2. Decompress a file" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();  // To clear the buffer before reading filenames

    std::cout << "Enter input filename: ";
    std::getline(std::cin, inputFilename);
    std::cout << "Enter output filename: ";
    std::getline(std::cin, outputFilename);

    if (choice == 1) {
        compressFile(inputFilename, outputFilename);
    } else if (choice == 2) {
        decompressFile(inputFilename, outputFilename);
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}
