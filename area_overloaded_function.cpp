#include <iostream>
using namespace std;

// Function to calculate the area of a circle
double area(double radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the area of a rectangle
double area(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle
double area(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double radius = 5.0;
    double length = 4.0, width = 6.0;
    double base = 3.0, height = 7.0;

    // Calculate areas using overloaded functions
    cout << "Area of circle: " << area(radius) << endl;
    cout << "Area of rectangle: " << area(length, width) << endl;
    cout << "Area of triangle: " << area(base, height) << endl;

    return 0;
}
