#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const = 0; // Pure virtual -> abstract class

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

int main() {
    // Create shape pointers
    Shape* shape1 = new Circle(5.0);         // Circle with radius 5
    Shape* shape2 = new Rectangle(4.0, 6.0); // Rectangle with length 4 and width 6

    // Use polymorphism to call area()
    cout << "Area of Circle: " << shape1->area() << endl;
    cout << "Area of Rectangle: " << shape2->area() << endl;

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
