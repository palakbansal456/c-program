#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class: Dog
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog says: Woof!" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat says: Meow!" << endl;
    }
};

// Derived class: Bird
class Bird : public Animal {
public:
    void makeSound() override {
        cout << "Bird says: Tweet!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    Animal* a3 = new Bird();

    a1->makeSound();
    a2->makeSound();
    a3->makeSound();

    delete a1;
    delete a2;
    delete a3;

    return 0;
}
