#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual void displayArea() = 0; // Pure virtual function (abstract class)
};

// Derived class: Circle
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    void displayArea() override {
        float area = 3.14159f * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    void displayArea() override {
        float area = length * width;
        cout << "Area of Rectangle: " << area << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    void displayArea() override {
        float area = 0.5f * base * height;
        cout << "Area of Triangle: " << area << endl;
    }
};

int main() {
    Shape* s1 = new Circle(5.0);
    Shape* s2 = new Rectangle(4.0, 6.0);
    Shape* s3 = new Triangle(3.0, 7.0);

    s1->displayArea();
    s2->displayArea();
    s3->displayArea();

    delete s1;
    delete s2;
    delete s3;

    return 0;
}
