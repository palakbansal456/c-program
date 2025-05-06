#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    // Constructor to initialize radius
    Circle(float r) : radius(r) {}

    // Declare friend function
    friend float calculateArea(Circle c);
};

// Definition of friend function
float calculateArea(Circle c) {
    return 3.14159f * c.radius * c.radius;
}

int main() {
    Circle c1(5.0);

    float area = calculateArea(c1);
    cout << "Area of the circle: " << area << endl;

    return 0;
}
