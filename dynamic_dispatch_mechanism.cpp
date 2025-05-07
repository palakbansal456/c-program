#include <iostream>
#include <vector>
using namespace std;

// Base class Shape with a virtual method draw
class Shape {
public:
    // Virtual function for drawing shapes
    virtual void draw() const {
        cout << "Drawing a generic shape." << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
public:
    // Override the draw method for Circle
    void draw() const override {
        cout << "Drawing a circle." << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    // Override the draw method for Rectangle
    void draw() const override {
        cout << "Drawing a rectangle." << endl;
    }
};

// Derived class Triangle
class Triangle : public Shape {
public:
    // Override the draw method for Triangle
    void draw() const override {
        cout << "Drawing a triangle." << endl;
    }
};

// Function to demonstrate dynamic dispatch
void renderShapes(const vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw();  // Polymorphic call to the draw method
    }
}

int main() {
    // Create objects of derived classes
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    // Store base class pointers to derived class objects
    vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);
    shapes.push_back(&triangle);

    // Call renderShapes to demonstrate dynamic dispatch
    cout << "Rendering shapes:\n";
    renderShapes(shapes);

    return 0;
}
