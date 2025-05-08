#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void mergeFiles(const std::vector<std::string>& inputFiles, const std::string& outputFile) {
    std::ofstream outFile(outputFile);  // Open the output file for writing
    
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the output file for writing!" << std::endl;
        return;
    }

    // Iterate over each input file
    for (const auto& inputFile : inputFiles) {
        std::ifstream inFile(inputFile);  // Open each input file for reading
        
        if (!inFile.is_open()) {
            std::cerr << "Error: Could not open input file: " << inputFile << std::endl;
            continue;  // Skip the file and proceed with the next
        }

        std::string line;
        // Read and write the contents of the input file to the output file
        while (std::getline(inFile, line)) {
            outFile << line << std::endl;  // Write each line from the input file to the output file
        }

        inFile.close();  // Close the input file after reading
    }

    outFile.close();  // Close the output file
    std::cout << "Files merged successfully into " << outputFile << std::endl;
}

int main() {
    int numFiles;
    std::string outputFile;

    // Get the number of files to merge and the output file name
    std::cout << "Enter the number of files to merge: ";
    std::cin >> numFiles;
    std::cin.ignore();  // To clear the input buffer

    std::vector<std::string> inputFiles(numFiles);
    
    std::cout << "Enter the output file name: ";
    std::getline(std::cin, outputFile);

    // Get the filenames of the input files
    for (int i = 0; i < numFiles; ++i) {
        std::cout << "Enter the name of input file #" << (i + 1) << ": ";
        std::getline(std::cin, inputFiles[i]);
    }

    // Merge the files
    mergeFiles(inputFiles, outputFile);

    return 0;
}
