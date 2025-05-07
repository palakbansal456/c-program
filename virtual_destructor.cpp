#include <iostream>
#include <memory>
using namespace std;

// Base class Shape
class Shape {
public:
    // Constructor for base class
    Shape() {
        cout << "Shape constructor called." << endl;
    }

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Shape() {
        cout << "Shape destructor called." << endl;
    }

    // Virtual function to demonstrate polymorphism
    virtual void draw() const {
        cout << "Drawing a shape." << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    // Constructor for derived class Circle
    Circle() {
        cout << "Circle constructor called." << endl;
    }

    // Virtual destructor for Circle class
    ~Circle() override {
        cout << "Circle destructor called." << endl;
    }

    // Override draw function
    void draw() const override {
        cout << "Drawing a Circle." << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    // Constructor for derived class Rectangle
    Rectangle() {
        cout << "Rectangle constructor called." << endl;
    }

    // Virtual destructor for Rectangle class
    ~Rectangle() override {
        cout << "Rectangle destructor called." << endl;
    }

    // Override draw function
    void draw() const override {
        cout << "Drawing a Rectangle." << endl;
    }
};

// Main program
int main() {
    // Create a pointer of type Shape, but point to derived class objects
    Shape* shape1 = new Circle();    // Create a Circle
    Shape* shape2 = new Rectangle(); // Create a Rectangle

    shape1->draw();  // Draw the circle
    shape2->draw();  // Draw the rectangle

    // Clean up: delete objects through base class pointer
    delete shape1; // This will call the Circle destructor
    delete shape2; // This will call the Rectangle destructor

    return 0;
}
