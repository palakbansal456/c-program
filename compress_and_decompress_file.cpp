#include <iostream>
#include <fstream>
#include <vector>
#include <zlib.h> // Include zlib for compression

class FileCompressor {
public:
    // Compress a file and save it as a new file
    static bool compressFile(const std::string& inputFile, const std::string& outputFile) {
        std::ifstream input(inputFile, std::ios::binary);
        if (!input.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
            return false;
        }

        std::vector<char> inputBuffer((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
        input.close();

        uLong sourceLen = inputBuffer.size();
        uLong destLen = compressBound(sourceLen);
        std::vector<Bytef> outputBuffer(destLen);

        int ret = compress(outputBuffer.data(), &destLen, reinterpret_cast<const Bytef*>(inputBuffer.data()), sourceLen);

        if (ret != Z_OK) {
            std::cerr << "Error during compression!" << std::endl;
            return false;
        }

        std::ofstream output(outputFile, std::ios::binary);
        if (!output.is_open()) {
            std::cerr << "Error opening output file!" << std::endl;
            return false;
        }

        output.write(reinterpret_cast<const char*>(outputBuffer.data()), destLen);
        output.close();

        std::cout << "File compressed successfully!" << std::endl;
        return true;
    }

    // Decompress a file and save it as a new file
    static bool decompressFile(const std::string& inputFile, const std::string& outputFile) {
        std::ifstream input(inputFile, std::ios::binary);
        if (!input.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
            return false;
        }

        std::vector<char> inputBuffer((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
        input.close();

        uLong sourceLen = inputBuffer.size();
        uLong destLen = sourceLen * 4;  // Allocate enough space for decompression (assumption)
        std::vector<Bytef> outputBuffer(destLen);

        int ret = uncompress(outputBuffer.data(), &destLen, reinterpret_cast<const Bytef*>(inputBuffer.data()), sourceLen);

        while (ret == Z_BUF_ERROR) { // If not enough space, increase the buffer size
            destLen *= 2;
            outputBuffer.resize(destLen);
            ret = uncompress(outputBuffer.data(), &destLen, reinterpret_cast<const Bytef*>(inputBuffer.data()), sourceLen);
        }

        if (ret != Z_OK) {
            std::cerr << "Error during decompression!" << std::endl;
            return false;
        }

        std::ofstream output(outputFile, std::ios::binary);
        if (!output.is_open()) {
            std::cerr << "Error opening output file!" << std::endl;
            return false;
        }

        output.write(reinterpret_cast<const char*>(outputBuffer.data()), destLen);
        output.close();

        std::cout << "File decompressed successfully!" << std::endl;
        return true;
    }
};

// Usage example:
int main() {
    std::string inputFile = "example.txt";    // Your input file to compress
    std::string compressedFile = "example_compressed.gz";  // Compressed output file
    std::string decompressedFile = "example_decompressed.txt";  // Decompressed output file

    // Compress the file
    if (FileCompressor::compressFile(inputFile, compressedFile)) {
        std::cout << "Compression completed!" << std::endl;
    }

    // Decompress the file
    if (FileCompressor::decompressFile(compressedFile, decompressedFile)) {
        std::cout << "Decompression completed!" << std::endl;
    }

    return 0;
}
