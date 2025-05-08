#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// Function to log error messages to a file
void logError(const std::string& errorMessage) {
    // Open the log file in append mode
    std::ofstream logFile("error_log.txt", std::ios::app);
    
    if (!logFile) {
        std::cerr << "Error: Could not open the log file." << std::endl;
        return;
    }

    // Get the current time for the log entry
    std::time_t now = std::time(0);
    char* dateTime = std::ctime(&now);
    
    // Remove newline character from the end of ctime string
    dateTime[strlen(dateTime) - 1] = '\0';  // Remove newline from time string

    // Write timestamp and error message to the log file
    logFile << "[" << dateTime << "] ERROR: " << errorMessage << std::endl;

    // Close the log file
    logFile.close();
}

int main() {
    // Simulating errors that need to be logged
    std::cout << "Program started..." << std::endl;

    // Example 1: File opening error
    std::ifstream file("nonexistent_file.txt");
    if (!file) {
        logError("Failed to open 'nonexistent_file.txt'");
    }

    // Example 2: Division by zero error
    int a = 5;
    int b = 0;
    if (b == 0) {
        logError("Attempted to divide by zero.");
    }

    // Example 3: Invalid user input
    int userInput = -1;
    if (userInput < 0) {
        logError("Invalid input: negative value entered.");
    }

    std::cout << "Program ended..." << std::endl;

    return 0;
}
