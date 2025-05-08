#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

void processFile(const char* filename) {
    // Open the file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Get the file size
    off_t fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1) {
        perror("Error determining file size");
        close(fd);
        return;
    }

    // Map the file into memory
    void* mappedMemory = mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mappedMemory == MAP_FAILED) {
        perror("Error mapping file into memory");
        close(fd);
        return;
    }

    // Process the mapped file (this example just prints the first 100 characters)
    char* data = static_cast<char*>(mappedMemory);
    std::cout << "Processing file..." << std::endl;
    for (size_t i = 0; i < 100 && i < fileSize; ++i) {
        std::cout << data[i];
    }
    std::cout << std::endl;

    // Clean up
    if (munmap(mappedMemory, fileSize) == -1) {
        perror("Error unmapping the file");
    }

    close(fd);
}

int main() {
    std::string filename;
    std::cout << "Enter the filename to process: ";
    std::getline(std::cin, filename);

    processFile(filename.c_str());

    return 0;
}
