#include <iostream>
#include <cstdio>  // For rename() and remove()

using namespace std;

int main() {
    // File names for demonstration
    const char* oldFileName = "old_file.txt";
    const char* newFileName = "new_file.txt";
    const char* fileToDelete = "new_file.txt";

    // Step 1: Renaming the file
    if (rename(oldFileName, newFileName) == 0) {
        cout << "File renamed successfully from '" << oldFileName << "' to '" << newFileName << "'." << endl;
    } else {
        perror("Error renaming file");
    }

    // Step 2: Deleting the file
    if (remove(fileToDelete) == 0) {
        cout << "File '" << fileToDelete << "' deleted successfully." << endl;
    } else {
        perror("Error deleting file");
    }

    return 0;
}
