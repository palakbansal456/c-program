#include <iostream>
#include <vector>
using namespace std;

// Base class Animal
class Animal {
public:
    // Virtual function to make sound (overridden by derived classes)
    virtual void makeSound() const {
        cout << "Animal makes a sound" << endl;
    }

    // Virtual function to move (overridden by derived classes)
    virtual void move() const {
        cout << "Animal moves" << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Animal() {}
};

// Derived class Mammal
class Mammal : public Animal {
public:
    // Override makeSound for Mammals
    void makeSound() const override {
        cout << "Mammal makes a sound: Growl!" << endl;
    }

    // Override move for Mammals
    void move() const override {
        cout << "Mammal walks on land." << endl;
    }
};

// Derived class Bird
class Bird : public Animal {
public:
    // Override makeSound for Birds
    void makeSound() const override {
        cout << "Bird makes a sound: Chirp!" << endl;
    }

    // Override move for Birds
    void move() const override {
        cout << "Bird flies in the sky." << endl;
    }
};

// Derived class Fish
class Fish : public Animal {
public:
    // Override makeSound for Fish
    void makeSound() const override {
        cout << "Fish makes a sound: Blub!" << endl;
    }

    // Override move for Fish
    void move() const override {
        cout << "Fish swims in water." << endl;
    }
};

// Function to simulate the ecosystem
void simulateEcosystem(const vector<Animal*>& animals) {
    for (const auto& animal : animals) {
        animal->makeSound();  // Polymorphic call to makeSound
        animal->move();       // Polymorphic call to move
    }
}

int main() {
    // Create animals of different types
    Mammal mammal;
    Bird bird;
    Fish fish;

    // Create a vector of Animal pointers
    vector<Animal*> animals;
    animals.push_back(&mammal);
    animals.push_back(&bird);
    animals.push_back(&fish);

    // Simulate the ecosystem by calling makeSound and move on each animal
    cout << "Simulating the ecosystem:" << endl;
    simulateEcosystem(animals);

    return 0;
}
