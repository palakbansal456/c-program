#include <iostream>
#include <cmath>
using namespace std;

// Base class: Shape
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const = 0; // Pure virtual function makes this an abstract class

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Overriding the area function for Circle
    double area() const override {
        return M_PI * radius * radius; // Area of circle = π * r^2
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;

public:
    // Constructor
    Square(double s) : side(s) {}

    // Overriding the area function for Square
    double area() const override {
        return side * side; // Area of square = side^2
    }
};

int main() {
    // Create objects of Circle and Square
    Shape* shape1 = new Circle(5.0);   // Circle with radius 5
    Shape* shape2 = new Square(4.0);   // Square with side 4

    // Use base class pointer to call derived class function (polymorphism)
    cout << "Area of Circle: " << shape1->area() << endl;
    cout << "Area of Square: " << shape2->area() << endl;

    // Clean up dynamically allocated memory
    delete shape1;
    delete shape2;

    return 0;
}
