#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void speak() const {
        cout << "Some animal sound" << endl;
    }

    // Virtual destructor
    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow!" << endl;
    }
};

// Derived class: Bird
class Bird : public Animal {
public:
    void speak() const override {
        cout << "Tweet! Tweet!" << endl;
    }
};

// Main function to test the classes
int main() {
    Animal* animals[3];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Bird();

    for (int i = 0; i < 3; ++i) {
        animals[i]->speak();  // Call speak using base class pointer
    }

    // Cleanup
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }

    return 0;
}
