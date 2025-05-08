#include <iostream>
#include <fstream>
#include <string>

void encryptDecryptFile(const std::string& inputFile, const std::string& outputFile, char key) {
    std::ifstream inFile(inputFile, std::ios::binary);  // Open input file in binary mode
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open the input file!" << std::endl;
        return;
    }

    std::ofstream outFile(outputFile, std::ios::binary);  // Open output file in binary mode
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the output file!" << std::endl;
        return;
    }

    char buffer;
    // Read the file byte by byte and apply XOR encryption/decryption
    while (inFile.get(buffer)) {
        // XOR the byte with the key to encrypt or decrypt
        buffer ^= key;
        outFile.put(buffer);  // Write the transformed byte to the output file
    }

    std::cout << "File encryption/decryption completed successfully." << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    int choice;
    std::string inputFile, outputFile;
    char key;

    std::cout << "Text File Encryption/Decryption Program using XOR Cipher" << std::endl;
    std::cout << "1. Encrypt a file" << std::endl;
    std::cout << "2. Decrypt a file" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();  // Ignore the leftover newline from the previous input

    std::cout << "Enter input filename: ";
    std::getline(std::cin, inputFile);
    std::cout << "Enter output filename: ";
    std::getline(std::cin, outputFile);

    std::cout << "Enter the encryption key (single character): ";
    std::cin >> key;

    if (choice == 1) {
        // Encrypt the file
        encryptDecryptFile(inputFile, outputFile, key);
    } else if (choice == 2) {
        // Decrypt the file
        encryptDecryptFile(inputFile, outputFile, key);
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}
