#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <random>

class Network {
private:
    int packetLossPercentage; // Simulate packet loss
    int maxDelay;            // Max delay in milliseconds

public:
    // Constructor: Initialize packet loss percentage and max delay
    Network(int packetLossPercentage = 10, int maxDelay = 100) {
        this->packetLossPercentage = packetLossPercentage;
        this->maxDelay = maxDelay;
        std::srand(std::time(0));  // Seed for random delay and packet loss
    }

    // Simulate sending a packet
    bool sendPacket(const std::string& packet, int receiverID) {
        std::cout << "Sending packet to Receiver " << receiverID << ": " << packet << std::endl;

        // Simulate packet loss
        if (isPacketLost()) {
            std::cout << "Packet lost during transmission!" << std::endl;
            return false;
        }

        // Simulate network delay
        simulateDelay();

        // Simulate receiving the packet at the receiver's end
        return receivePacket(packet, receiverID);
    }

    // Simulate receiving a packet at the receiver's end
    bool receivePacket(const std::string& packet, int receiverID) {
        std::cout << "Receiver " << receiverID << " received packet: " << packet << std::endl;

        // Simulate acknowledgment
        return acknowledgeReceipt(receiverID);
    }

    // Simulate acknowledgment of packet reception
    bool acknowledgeReceipt(int receiverID) {
        std::cout << "Acknowledgment sent back from Receiver " << receiverID << std::endl;
        return true;
    }

    // Simulate packet loss (based on packetLossPercentage)
    bool isPacketLost() {
        return rand() % 100 < packetLossPercentage;
    }

    // Simulate network delay (random delay between 0 and maxDelay ms)
    void simulateDelay() {
        int delay = rand() % maxDelay;
        std::cout << "Simulating network delay of " << delay << " ms..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
};

// Example Usage
int main() {
    Network network(20, 200); // 20% packet loss, max delay of 200 ms

    std::string packet = "Hello, this is a test packet!";
    int receiverID = 1;

    // Simulate sending and receiving packets
    if (network.sendPacket(packet, receiverID)) {
        std::cout << "Packet transmission successful." << std::endl;
    } else {
        std::cout << "Packet transmission failed." << std::endl;
    }

    return 0;
}
