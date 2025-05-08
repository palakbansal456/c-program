#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);  // Open the file for reading
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return -1;
    }

    int count = 0;
    std::string line;

    // Read each line of the file
    while (std::getline(file, line)) {
        // Convert the line to a stringstream for word-by-word processing
        std::stringstream ss(line);
        std::string currentWord;

        // Read words one by one
        while (ss >> currentWord) {
            // Compare the current word with the target word
            if (currentWord == word) {
                count++;
            }
        }
    }

    file.close();  // Close the file
    return count;
}

int main() {
    std::string filename, word;

    // Ask the user for the filename and word to search
    std::cout << "Enter the filename to search in: ";
    std::cin >> filename;

    std::cout << "Enter the word to search for: ";
    std::cin >> word;

    // Call the function to count occurrences of the word
    int occurrences = countWordOccurrences(filename, word);

    if (occurrences != -1) {
        std::cout << "The word '" << word << "' occurred " << occurrences << " time(s) in the file." << std::endl;
    }

    return 0;
}
