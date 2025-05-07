#include <iostream>
#include <cmath> // for M_PI

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const {
        return 0.0;
    }

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
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

// Test the shape classes
int main() {
    Shape* shapes[3];

    shapes[0] = new Circle(5.0);       // Circle with radius 5
    shapes[1] = new Rectangle(4.0, 6.0); // Rectangle 4x6
    shapes[2] = new Triangle(3.0, 7.0);  // Triangle base=3, height=7

    for (int i = 0; i < 3; ++i) {
        std::cout << "Area of shape " << i + 1 << " = " << shapes[i]->area() << std::endl;
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}
