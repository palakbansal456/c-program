#include <iostream>
using namespace std;

// Virtual base class
class Animal {
public:
    Animal() {
        cout << "Animal constructor" << endl;
    }

    void sound() {
        cout << "Animal makes a sound!" << endl;
    }

    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

// Derived class Mammal from virtual base Animal
class Mammal : virtual public Animal {
public:
    Mammal() {
        cout << "Mammal constructor" << endl;
    }

    void move() {
        cout << "Mammal moves" << endl;
    }

    ~Mammal() {
        cout << "Mammal destructor" << endl;
    }
};

// Derived class Bird from virtual base Animal
class Bird : virtual public Animal {
public:
    Bird() {
        cout << "Bird constructor" << endl;
    }

    void fly() {
        cout << "Bird flies" << endl;
    }

    ~Bird() {
        cout << "Bird destructor" << endl;
    }
};

// Derived class Bat from both Mammal and Bird
class Bat : public Mammal, public Bird {
public:
    Bat() {
        cout << "Bat constructor" << endl;
    }

    void sound() {
        cout << "Bat makes a screeching sound!" << endl;
    }

    ~Bat() {
        cout << "Bat destructor" << endl;
    }
};

int main() {
    cout << "Creating Bat object" << endl;
    Bat bat;  // Bat inherits from both Mammal and Bird

    bat.sound();  // Bat's version of sound
    bat.move();   // Mammal's move
    bat.fly();    // Bird's fly

    return 0;
}
